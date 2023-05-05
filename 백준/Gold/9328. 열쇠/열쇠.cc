#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define all(x) x.begin(), x.end()
#define FOR(X,N) for(int X = 0; X < N; ++X)
#define ll long long
#define pii pair<int,int>
using namespace std;
//#####################################################

int testCase;
enum _SYMBOL_ {
	EMPTY = '.',
	WALL = '*',
	DOCUMENT = '$'
};
int OPEN = 'a' - 'A';
const int direction[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };

const inline bool isEmpty(const char& _symbol) { return (_symbol == EMPTY); }
const inline bool isWall(const char &_symbol) { return (_symbol == WALL); }
const inline bool isDocument(const char &_symbol) { return (_symbol == DOCUMENT); }
const inline bool isKey(const char &_symbol) { return ('a' <= _symbol && _symbol <= 'z'); }
const inline bool isNewKey(const vector<bool> &keys, const char &key) { return !(keys[key + 0]); }
const inline bool isDoor(const char &_symbol) { return ('A' <= _symbol && _symbol <= 'Z'); }
const inline bool canOpen(const vector<bool> &keys, const char &door) { return keys[door + OPEN]; }

int bfs(const pii &boardSize, vector<vector<char>>& board, const pii start, vector<bool> keys) {

	vector<vector<bool>> visited(boardSize.first, vector<bool>(boardSize.second, false));
	queue<pii> Q;
	Q.push(start);
	visited[start.first][start.second] = true;

	int ret = 0;
	bool out = false;
	while (!Q.empty() && !out) {

		auto [cx, cy] = Q.front(); Q.pop();

		for (auto direc : direction) {
			int nx = cx + direc[0], ny = cy + direc[1];
			if (nx < 0 || nx >= boardSize.first || ny < 0 || ny >= boardSize.second) continue;

			char& nextBoard = board[nx][ny];
			if (isWall(nextBoard) || visited[nx][ny]) continue;
			else if (isKey(nextBoard)) {
				if (isNewKey(keys, nextBoard)) {
					//new branch
					keys[nextBoard] = true;
					ret += bfs(boardSize, board, { nx,ny }, keys);
					out = true;
					break;
				}
				else {
					Q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
			else if (isDoor(nextBoard)) {
				if (canOpen(keys, nextBoard)) {
					Q.push({ nx, ny });
					visited[nx][ny] = true;
				}
			}
			else if (isDocument(nextBoard)) {
				++ret;
				nextBoard = EMPTY;
				Q.push({ nx,ny });
				visited[nx][ny] = true;
			}
			else if (isEmpty(nextBoard)) {
				Q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}

	return ret;
}

int solution() {
	int height, width;
	cin >> height >> width;

	vector<vector<char>> board(height + 2, vector<char>(width + 2, EMPTY));
	pii boardSize = { height + 2, width + 2 };
	vector<bool> keys('z' + 1, false);

	FOR(x, height) {
		string temp;
		cin >> temp;
		FOR(y, width) 
			board[x + 1][y + 1] = temp[y];
	}
	string key;
	cin >> key;
	for (char k : key) 
		keys[k + 0] = true;
	
	return bfs(boardSize, board, { 0,0 }, keys);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();



	cin >> testCase;
	while (testCase--) {
		cout << solution() << "\n";
	}
	return 0;
}