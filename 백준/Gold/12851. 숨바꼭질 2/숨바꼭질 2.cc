#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
//#include <string>
//#include <tuple>
//#include <stack>
#include <array>
//#include <format>
#define INT_MAX 2147483647
#define LLONG_MAX 9'223'372'036'854'775'807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; ++VAR)
using namespace std;
//#######################################################

vector<int> dis; // S로부터 V까지의 최단 거리
vector<vector<pair<int, int>>> adj; // V정점에서 연결되어 있는 노드와 가중치의 배열{v,d}



int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int s, e;
	cin >> s >> e;

	queue<array<int,2>> bfs;
	vector<bool> visited(100'001, false);
	vector<pair<int,int>> p(100'001, {0,0});
	p[s] = { 0,1 };
	visited[s] = true;
	bfs.push({s,0});

	while (!bfs.empty()) {
		auto [cur, d] = bfs.front(); bfs.pop();
		if (cur + 1 <= 100000 ) {
			if (!visited[cur + 1]) {
				bfs.push({ cur + 1,d + 1 });
				p[cur + 1] = { d + 1,p[cur].second};
				visited[cur + 1] = true;
			}
			else {
				if (d + 1 == p[cur + 1].first) p[cur + 1].second += p[cur].second;
			}
			
		}
		if (cur - 1 >= 0) {
			if (!visited[cur - 1]) {
				bfs.push({ cur - 1,d + 1 });
				p[cur - 1] = { d + 1,p[cur].second };
				visited[cur - 1] = true;
			}
			else {
				if (d + 1 == p[cur - 1].first) p[cur - 1].second += p[cur].second;
			}

		}
		if (cur * 2 <= 100000) {
			if (!visited[cur * 2]) {
				bfs.push({ cur * 2,d + 1 });
				p[cur * 2] = { d + 1,p[cur].second };
				visited[cur * 2] = true;
			}
			else {
				if (d + 1 == p[cur * 2].first) p[cur * 2].second += p[cur].second;
			}
		}
	}

	cout << p[e].first << "\n" << p[e].second;
	return 0;
}