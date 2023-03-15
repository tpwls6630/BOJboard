#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
//#include <cstring>
#include <string>
//#include <sstream>
//#include <stack>
//#include <typeinfo>
#include <array>
//#include <bitset>
//#include <format>

#define llong long long
#define vi vector<int> 
#define mat vector<vi> 
#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;

int n, m, r;
vector<int> item;
vector<vector<pair<int, int>>> edge;

int dijkstra(int start) {
	vector<int> dis(n, INT_MAX);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dis[start] = 0;
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (-d > dis[u]) continue;
		for (auto [v, c] : edge[u]) {
			if (dis[v] > c + dis[u]) {
				dis[v] = c + dis[u];
				pq.push({ -dis[v], v });
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (dis[i] <= m) ret += item[i];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> r;
	item = vector<int>(n);
	edge = vector<vector<pair<int, int>>>(n);
	int ans = 0;
	FOR(i, n) {
		cin >> item[i];
	}
	FOR(i, r) {
		int a, b, d;
		cin >> a >> b >> d;
		edge[a - 1].push_back({ b - 1,d });
		edge[b - 1].push_back({ a - 1,d });
	}

	FOR(i, n) {
		ans = max(ans, dijkstra(i));
	}
	
	cout << ans;
	return 0;
}