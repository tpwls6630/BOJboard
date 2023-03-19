#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
//#include <deque>
#include <string>
//#include <tuple>
//#include <stack>
//#include <sstream>
//#include <map>
#include <array>
//#include <format>

#define INT_MAX 2147483647
#define LLONG_MAX 9'223'372'036'854'775'807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; ++VAR)
using namespace std;
//#######################################################

int n, m,s,e;
vector<pair<int, int>> ele;

int gcd(const int a, const int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	ele = vector<pair<int, int>>(m);
	vector<vector<int>> E(m); //엘리베이터간의 간선(같은 층이 있음)
	vector<bool> s_ele(m), e_ele(m); //시작층이 있는 엘레베이터, 도착층이 있는 엘레베이터
	

	FOR(i, m) {
		cin >> ele[i].first >> ele[i].second;
	}
	cin >> s >> e;

	FOR(i, m) {
		if ((s - ele[i].first) % ele[i].second == 0 && s >= ele[i].first) s_ele[i] = true;
		if ((e - ele[i].first) % ele[i].second == 0 && e >= ele[i].first) e_ele[i] = true;
		for (int j = i - 1; j >= 0; j--) {
			int a = i, b = j;
			if (ele[a].first < ele[b].first) swap(a, b);
			for (int d = 0; d * ele[a].second + ele[a].first <= n; d++) {
				if ((((ele[a].first - ele[b].first) % ele[b].second) + ele[a].second * d % ele[b].second) % ele[b].second == 0) {
					E[a].push_back(b);
					E[b].push_back(a);
					break;
				}
			}
		}
	}



	vector<int> ans;
	int asize = INT_MAX;
	for (int i = 0; i < m; i++) {
		if (s_ele[i]) {
			//bfs

			priority_queue<array<int, 2>> pq;
			vector<array<int, 2>> path(m, { INT_MAX,-1 });
			int lastele = -1, least = INT_MAX;
			pq.push({ 0,i });
			path[i][0] = 0;

			while (!pq.empty()) {
				auto [d, cur] = pq.top(); pq.pop();
				if (-d > path[cur][0]) continue;
				if (e_ele[cur]) {
					if (least >= -d) {
						least = -d;
						lastele = cur;
					}
				}
				for (auto el : E[cur]) {
					if (path[el][0] > -d + 1) {
						path[el] = { -d + 1, cur };
						pq.push({ -path[el][0],el });
					}
				}
			}
			/*
			queue<array<int,3>> bfs;
			vector<pair<bool,int>> visited(m, {false, -1});
			int a = INT_MAX;
			int lastele = -1;
			bfs.push({ i, 0 , -1});
			visited[i].first = true;

			while (!bfs.empty()) {
				auto [cur, d, pre] = bfs.front(); bfs.pop();
				if (e_ele[cur]) {
					if (a > d) {
						a = d;
						lastele = cur;
						continue;
					}
				}
				for (auto next : E[cur]) {
					if (!visited[next].first) {
						bfs.push({ next, d + 1 });
						visited[next] = { true, cur };
					}
				}
			}*/
			if (lastele == -1) continue;
			if (asize >= least) {
				asize = least;
				vector<int>().swap(ans);
				ans.push_back(lastele);
				while (!s_ele[lastele]) {
					lastele = path[lastele][1];
					ans.push_back(lastele);
				}
			}
			
		}
	}

	if (ans.size() == 0) {
		cout << -1;
		return 0;
	}
	cout << ans.size() << "\n";
	for (auto iter = ans.rbegin(); iter != ans.rend(); iter++) {
		cout << *iter + 1 << "\n";
	}

	return 0;
}