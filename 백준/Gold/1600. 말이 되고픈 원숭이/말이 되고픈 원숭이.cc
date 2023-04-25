#include <iostream>
#include <vector>
#include <array>
#include <queue>
//#include <format>

#define ll long long
#define pii pair<int,int>
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//

int k,w,h;

bool outOfBorder(int x, int y) {
	return (x < 0 || x >= h || y < 0 || y >= w);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	vector<pii> direc = { {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}  };
	vector<pii> udlr = { {1,0},{0,1},{-1,0},{0,-1} };

	
	cin >> k >> w >> h;
	vector<vector<int>> wall(h, vector<int>(w));
	vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(w, vector<bool>(k + 1, false)));
	FOR(i, h)
		FOR(j, w)
			cin >> wall[i][j];

	queue<array<int,4>> q; // {x, y, depth, knight moves}
	q.push({ 0,0,0,0 });
	visited[0][0][0] = true;
	while (!q.empty()) {
		auto [x, y, depth, knightMoves] = q.front(); q.pop();

		if (x == h - 1 && y == w - 1) {
			cout << depth;
			return 0;
		}

		if (knightMoves < k) {
			for (auto [dx, dy] : direc) {
				int nx = x + dx, ny = y + dy;
				if (outOfBorder(nx, ny)) continue;
				if (wall[nx][ny]) continue;
				if (!visited[nx][ny][knightMoves + 1]) {
					q.push({ nx,ny,depth + 1,knightMoves + 1 });
					visited[nx][ny][knightMoves + 1] = true;
				}
			}
		}
		for (auto [dx, dy] : udlr) {
			int nx = x + dx, ny = y + dy;
			if (outOfBorder(nx, ny)) continue;
			if (wall[nx][ny]) continue;
			if (!visited[nx][ny][knightMoves]) {
				q.push({ nx,ny,depth + 1,knightMoves });
				visited[nx][ny][knightMoves] = true;
			}
		}
	}
	cout << -1;
	return 0;
}