#include <algorithm>
#include <iostream>
#include <vector>
//#include <queue>
//#include <cmath>
//#include <cstring>
//#include <string>
//#include <sstream>
//#include <stack>
//#include <typeinfo>
//#include <array>
//#include <bitset>
//#include <format>
#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//

int n, m;
vector<vector<int>> dis;
vector<pair<int, int>> E;
vector<int> parent, mins;
int f(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = f(parent[x]);
}

bool uni(int u, int v) {
	int U = f(u), V = f(v);
	if (U == V) return false;
	parent[V] = U;
	return true;
}

int floid(vector<int> &g) {

	for (auto k : g)
		for (auto i : g)
			for (auto j : g) {
				if (dis[i][j] > dis[i][k] + dis[k][j])dis[i][j] = dis[i][k] + dis[k][j];
				if (i == j) dis[i][j] = 0;
			}
	int tmax = 100000;
	int ret = 0;
	for (auto i : g) {
		int pmax = 0;
		for (auto j : g)
			pmax = max(pmax, dis[i][j]);
		if (tmax > pmax) {
			tmax = pmax;
			ret = i;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	parent = vector<int>(n + 1, -1);
	mins = vector<int>(n + 1, 100000);
	dis = vector<vector<int>>(n + 1, vector<int>(n + 1, 100000));

	FOR(i, m) {
		int a, b;
		cin >> a >> b;
		E.push_back({a,b});
		dis[a][b] = dis[b][a] = 1;
	}

	for (auto e : E) 
		uni(e.first, e.second);

	vector<vector<int>> group(n+1);
	for (int i = 1; i <= n; i++) {
		group[f(i)].push_back(i);
	}
	
	vector<int> ans;
	for (auto v : group) {
		if (v.size() != 0) {
			ans.push_back(floid(v));
		}
	}

	sort(all(ans));

	cout << ans.size() << "\n";
	for (auto e : ans) {
		cout << e << "\n";
	}

	return 0;
}