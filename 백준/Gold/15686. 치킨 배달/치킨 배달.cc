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
//#include <array>
//#include <format>

#define INT_MAX 2147483647
#define LLONG_MAX 9'223'372'036'854'775'807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; ++VAR)
using namespace std;
//#######################################################

int n, m;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	vector<vector<int>> city(n,vector<int>(n));
	vector<pair<int, int>> bhc, house;
	
	FOR(i, n)
		FOR(j, n) {
			cin >> city[i][j];
			if (city[i][j] == 2)
				bhc.push_back({ i,j });
			else if (city[i][j] == 1)
				house.push_back({ i,j });
		}
	
	vector<vector<int>> bhc_dist(house.size(), vector<int>(bhc.size()));

	for (int i = 0; i < house.size(); i++) {
		for (int j = 0; j < bhc.size(); j++) {
			bhc_dist[i][j] = abs(house[i].first - bhc[j].first) + abs(house[i].second - bhc[j].second);
		}
	}

	vector<bool> homin(bhc.size(), 1);
	for (int i = 0; i < m; i++)
		homin[i] = 0;
	
	int ans = INT_MAX;

	do {
		int sum = 0;
		vector<int> min_dist(house.size(),INT_MAX);
		for (int i = 0; i < house.size(); i++) {
			for (int j = 0; j < bhc.size(); j++) {
				if (homin[j]) continue;
				min_dist[i] = min(min_dist[i], bhc_dist[i][j]);
			}
		}
		for (auto e : min_dist) {
			sum += e;
		}
		ans = min(ans, sum);

	} while (next_permutation(all(homin)));

	cout << ans;

	return 0;
}