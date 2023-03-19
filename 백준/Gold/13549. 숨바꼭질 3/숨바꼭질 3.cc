#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
//#include <deque>
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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int s, e;
	cin >> s >> e;

	deque<pair<int,int>> dq;
	vector<int> dis(100'001, INT_MAX);

	dq.push_back({ s,0 });
	dis[s] = 0;

	while (!dq.empty()) {
		auto [cur, d] = dq.front(); dq.pop_front();
		if (cur == e) { cout << d; return 0; }
		if (cur + 1 <= 100000 && dis[cur + 1] > dis[cur] + 1) {
			dq.push_back({ cur + 1,d + 1 });
			dis[cur + 1] = dis[cur] + 1;
		}
		if (cur - 1 >= 0 && dis[cur - 1] > dis[cur] + 1) {
			dq.push_back({ cur - 1,d + 1 });
			dis[cur - 1] = dis[cur] + 1;
		}
		if (cur * 2 <= 100000 && dis[cur * 2] > dis[cur]) {
			dq.push_front({ cur * 2,d });
			dis[cur * 2] = dis[cur];
		}
	}

	return 0;
}