#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define all(x) x.begin(), x.end()
#define FOR(X,N) for(int X = 0; X < N; ++X)
#define FOR1(X,N) for(int X = 1; X <= N; ++X)
#define ll long long
#define pii pair<int,int>
using namespace std;
//############################################################################

int facto[9];
const int direc[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

// use 3 types of data
// 1. board : 3 x 3 board
// 2. permutation(int) : 

void factoInit() {
	facto[0] = 1;
	for (int i = 1; i < 9; i++) {
		facto[i] = facto[i - 1] * i;
	}
}
//int permuToIdx(int permutation) {
//	// 123456789 => 0
//	// 987654321 => 9! - 1
//	// 468192357 => 3 x 8! + 4 x 7! + 5 x 6! + 0 x 5! + 4 x 4! + 0 x 3! + 0 x 2! + 0 x 1! + 0 x 0! = 144816
//	int arr[9] = { 0, }, lessRight[9] = { 0, };
//	for (int idx = 8; idx >= 0; idx--) {
//		arr[idx] = permutation % 10;
//		permutation /= 10;
//	}
//	for (int i = 0; i < 9; i++) {
//		for (int j = i + 1; j < 9; j++) {
//			if (arr[i] > arr[j]) ++lessRight[i];
//		}
//	}
//	int ret = 0;
//	FOR(i, 9) {
//		ret += facto[8 - i] * lessRight[i];
//	}
//
//	return ret;
//}
//int idxToPermu(int idx) {
//	// 1 => 123456789
//	// 9! => 987654321
//	// 144816 => 468192357
//	bool ocupied[10] = { 0, };
//	ll ret = 0;
//	FOR(i, 9) {
//		int ri = 8 - i;
//		int r = idx / facto[ri] + 1, cnt = 0;
//		for (int i = 1; i <= 9; i++) {
//			if (ocupied[i] == false) cnt++;
//			if (r == cnt) {
//				ocupied[i] = true;
//				ret += i;
//				break;
//			}
//		}
//		idx -= facto[ri] * (r - 1);
//		if(i < 8) ret *= 10;
//	}
//	return ret;
//}
inline vector<vector<int>> permuToBoard(int permutation) {
	vector<vector<int>> ret(3, vector<int>(3, 0));
	for (int i = 8; i >= 0; i--) {
		ret[i / 3][i % 3] = permutation % 10;
		permutation /= 10;
	}
	return ret;
}
inline int boardToPermu(vector<vector<int>>& board) {
	int ret = 0;
	for (int i = 0; i < 9; i++) {
		ret += board[i / 3][i % 3];
		if (i < 8) ret *= 10;
	}
	return ret;
}
vector<int> nextPermutation(int permutation) {
	vector<vector<int>> board = permuToBoard(permutation);
	vector<int> ret;
	for (int i = 0; i < 9; i++) {
		// find 9(= 0)
		if (board[i / 3][i % 3] == 9) {

			int x = i / 3, y = i % 3;

			for (auto [dx, dy] : direc) {
				int nx = x + dx, ny = y + dy;
				if (nx < 0 || nx > 2 || ny < 0 || ny > 2) continue;
				vector<vector<int>> nextBoard(board);
				swap(nextBoard[x][y], nextBoard[nx][ny]);
				ret.push_back(boardToPermu(nextBoard));
			}
			break;
		}
	}
	return ret;
}

int solution(int startPermutation) {

	set<int> visited;
	queue<pii> bfs;

	bfs.push({ startPermutation, 0 });
	visited.insert(startPermutation);
	while (!bfs.empty()) {
		auto [cur, depth] = bfs.front(); bfs.pop();
		if (cur == 123456789) {
			return depth;
		}
		for (auto next : nextPermutation(cur)) {
			if (visited.find(next) == visited.end()) {
				bfs.push({ next, depth + 1 });
				visited.insert(next);
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();

	factoInit();

	//vector<int> sample = { 3,4,5,0,4,0,0,0,0 };
	//cout << permuToIdx(468192357) << endl;
	//cout << idxToPermu(144816);

	
	int start = 0;
	FOR(i, 9) {
		int temp; cin >> temp;
		if (temp == 0) temp = 9;
		start += temp;
		if (i < 8) start *= 10;
	}

	cout << solution(start);
	

	return 0;
}