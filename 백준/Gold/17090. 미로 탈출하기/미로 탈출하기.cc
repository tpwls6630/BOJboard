#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int,int>
#define ll long long
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)

using namespace std;
//########################################################################//

int n, m;
int U = 'U' - 'A', R = 'R' - 'A', D = 'D' - 'A', L = 'L' - 'A';

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	vector<vector<int>> board(n + 2, vector<int>(m + 2, 0));
	int direc[4][3] = {{D,-1,0},{L,0,1},{U,1,0},{R,0,-1}};

	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			board[i][j] = c - 'A';
		}
	}

	vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, false));

	//bfs
	queue<pii> bfs;
	bfs.push({ 0,0 });
	visited[0][0] = true;
	int ans = 0;
	while (!bfs.empty()) {
		auto [x, y] = bfs.front(); bfs.pop();
		for (auto d : direc) {
			int nx = x + d[1], ny = y + d[2];
			if (nx < 0 || nx>n + 1 || ny<0 || ny>m + 1)continue;
			if (!visited[nx][ny]) {
				if (board[nx][ny] == 0) {
					bfs.push({ nx,ny });
					visited[nx][ny] = true;
				}
				else if (board[nx][ny] == d[0]) {
					ans++;
					bfs.push({ nx,ny });
					visited[nx][ny] = true;
				}
			}
		}
	}

	cout << ans;

	return 0;
}
