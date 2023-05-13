#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define all(x) x.begin(), x.end()
#define FOR(X,N) for(int X = 0; X < N; ++X)
#define FOR1(X,N) for(int X = 1; X <= N; ++X)
#define ll long long
#define pii pair<int,int>
using namespace std;
//############################################################################

const bool STAR = true, EMPTY = false;
const int c5t2 = 31<<20;
typedef vector<vector<bool>> BOARD;
const int direc[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int numStar;

inline int hashing(BOARD &board) {
	// 5 x 5 board
	int ret = 0;
	for (int i = 0; i < 25; i++) {
		ret += board[i / 5][i % 5];
		ret <<= 1;
	}
	ret >>= 1;
	return ret;
}
vector<BOARD> nextBoard(const BOARD& initialBoard, const vector<bool> &visited) {
	vector<BOARD> ret;
	for (int i = 0; i < 25; i++) {

		int x = i / 5, y = i % 5;

		if (initialBoard[x][y] == STAR) {
			for (auto [dx, dy] : direc) {

				int nx = x + dx, ny = y + dy;
				if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;

				BOARD nBoard(initialBoard);
				swap(nBoard[x][y], nBoard[nx][ny]);
				if (!visited[hashing(nBoard)])
					ret.push_back(nBoard);
			}
		}
	}
	return ret;
}
const bool checkEndPosition(const BOARD& board) {

	int cnt = 0;

	for (int i = 0; i < 25; i++) {

		int x = i / 5, y = i % 5;

		if (board[x][y] == STAR) {

			//bfs
			vector<bool> visited(25, false);
			queue<pii> checkstar;

			checkstar.push({ x,y });
			visited[x * 5 + y] = true;

			while (!checkstar.empty()) {

				auto [cx, cy] = checkstar.front(); checkstar.pop();

				if (board[cx][cy] == STAR) ++cnt;
				for (auto [dx, dy] : direc) {

					int nx = cx + dx, ny = cy + dy;
					if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;

					if (!visited[5 * nx + ny] && board[nx][ny] == STAR) {
						checkstar.push({ nx,ny });
						visited[5 * nx + ny] = true;
					}
				}
			}
			break;
		}
	}
	return cnt == numStar;
}
int solution(BOARD&initialBoard) {

	vector<bool> visited(c5t2, false);
	queue < pair<BOARD, int>> bfs;

	bfs.push({ initialBoard, 0 });
	visited[hashing(initialBoard)] = true;

	while (!bfs.empty()) {
		auto [curBoard, depth] = bfs.front(); bfs.pop();
		if (checkEndPosition(curBoard)) {
			return depth;
		}
		for (auto nBoard : nextBoard(curBoard, visited)) {
			int hash = hashing(nBoard);
			if (!visited[hash]) {
				bfs.push({ nBoard, depth + 1 });
				visited[hash] = true;
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();

	BOARD initialBoard(5, vector<bool>(5, EMPTY));

	FOR(i, 5) {
		string temp; cin >> temp;
		FOR(j, 5) {
			char c = temp[j];
			if (c == '*') {
				numStar++;
				initialBoard[i][j] = STAR;
			}
		}
	}
	cout << solution(initialBoard);
	return 0;
}