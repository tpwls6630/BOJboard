#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
//#include <set>
//#include <unordered_set>
//#include <sstream>
//#include <deque>
//#include <tuple>
#include <stack>
//#include <unordered_map>
//#include <typeinfo>
#include <array>
//#include <bitset>
//#include <format>
//#include <random>


#define llong long long
#define vi vector<int> 
#define mat vector<vi> 
#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
/*
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dis(0, 1e3);
*/

vector<int> parent, height;


struct edge {
	int a = 0, b = 0, c = 0;

	edge(int A, int B, int C) : a(A), b(B), c(C) {}
	bool operator<(edge e) {
		return c < e.c;
	}
};

int Find(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int u, int v) {
	int U = Find(u), V = Find(v);
	if (U == V) return false;

	if (height[U] > height[V]) swap(U, V);
	parent[U] = V;

	if (height[U] == height[V]) height[V]++;
	return true;
}

int mst(vector<edge>& E, int group) {

	parent = vector<int>(group + 2, -1);
	height = vector<int>(group + 2, 0);
	int ret = 0, cnt = 0;
	for (auto e : E) {
		if (Union(e.a, e.b)) {
			ret += e.c;
			cnt++;
		}
		if (cnt == group - 1) 
			return ret;
		
	}
	if (cnt != group - 1)
		return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> ground(n, vector<int>(m));
	
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			cin >> ground[i][j];
	
	int group = 1;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (ground[x][y] == 1) {
				queue<pair<int, int>> q;
				q.push({ x,y });
				ground[x][y] = ++group;
				while (!q.empty()) {//bfs
					auto [cx, cy] = q.front();
					q.pop();
					int d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
					for (auto e : d) {
						int nx = cx + e[0], ny = cy + e[1];
						if (nx < 0 || nx > n - 1 || ny <0 || ny>m - 1) continue;
						if (ground[nx][ny] == 1) {
							ground[nx][ny] = group; q.push({ nx,ny });
						}
					}
				}
			}
		}
	}

	/*
	for (auto v : ground) {
		for (auto e : v) {
			cout << e << ' ';
		}
		cout << endl;
	}
	*/

	vector<edge> E;
	for (int row = 0; row < n; row++) {
		int cur = 0, y = 0;
		for (int col = 0; col < m; col++) {
			int& g = ground[row][col];
			if (g != 0) {
				if (cur != 0 && g != cur) {
					if(col - y > 2)
						E.push_back({cur,g,col - y - 1});
				}
				y = col;
				cur = g;
			}
		}
	}

	for (int col = 0; col < m; col++) {
		int cur = 0, x = 0;
		for (int row = 0; row < n; row++) {
			int& g = ground[row][col];
			if (g != 0) {
				if (cur != 0 && g != cur) {
					if (row - x > 2)
						E.push_back({ cur,g,row - x - 1 });
				}
				x = row;
				cur = g;
			}
		}
	}

	sort(all(E));

	cout << mst(E, group - 1);
	return 0;
 }
