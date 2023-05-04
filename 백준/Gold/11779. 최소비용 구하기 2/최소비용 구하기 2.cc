#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define all(x) x.begin(), x.end()
#define FOR(X,N) for(int X = 0; X < N; ++X)
#define ll long long
#define pii pair<int,int>
using namespace std;
//#####################################################

int n, m;
vector<pii> dist; // first->distance from start node, second->parent node
const int INF = 10'000'000'000;
void dijkstra(vector<vector<pii>> &adj, int start) {

	priority_queue<pii> pq;
	pq.push({ 0, start });
	dist[start] = { 0,-1 }; 
	while (!pq.empty()) {
		auto [d, cur] = pq.top(); pq.pop();
		if (-d > dist[cur].first) continue;
		for (auto [next, w] : adj[cur]) {
			if (dist[next].first > dist[cur].first + w) {
				dist[next].first = dist[cur].first + w;
				dist[next].second = cur;
				pq.push({ -dist[next].first, next });
			}
		}
	}
}
int main() {

	cin >> n >> m;
	vector<vector<pii>> adj(n);
	dist = vector<pii>(n, { INF, -1 });
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		--a; --b;
		adj[a].push_back({ b,w });
	}

	int start, end;
	cin >> start >> end;
	--start; --end;
	dijkstra(adj, start);
	
	stack<int> ans;
	int cur = end;
	int cnt = 0;
	while (dist[cur].second != -1) {
		ans.push(cur); ++cnt;
		cur = dist[cur].second;
	}

	cout << dist[end].first << "\n";
	cout << ++cnt << "\n" << start + 1 << ' ';
	while (!ans.empty()) {
		cout << ans.top() + 1 << ' ';
		ans.pop();
	}
}