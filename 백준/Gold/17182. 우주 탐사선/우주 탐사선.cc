#include <algorithm>
#include <iostream>
#include <vector>

#define all(x) x.begin(), x.end()
#define FOR(X,N) for(int X = 0; X < N; ++X)
#define FOR1(X,N) for(int X = 1; X <= N; ++X)
#define ll long long
#define pii pair<int,int>
using namespace std;
//############################################################################

const int INF = 10'000'000;
int n;
vector<vector<int>> floidDist;

void floid() {
	FOR(k, n) {
		FOR(i, n) {
			FOR(j, n) {
				floidDist[i][j] = min(floidDist[i][j], floidDist[i][k] + floidDist[k][j]);
			}
		}
	}
}
int solution(int startPlanet) {
	vector<int> travelPlan = { startPlanet };
	FOR(i, n) {
		if (i == startPlanet) continue;
		travelPlan.push_back(i);
	}

	int ret = INF;
	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += floidDist[travelPlan[i]][travelPlan[i + 1]];
		}
		ret = min(ret, sum);
	} while (next_permutation(all(travelPlan)) && travelPlan[0] == startPlanet);
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();

	int startPlanet;
	cin >> n >> startPlanet;
	floidDist = vector<vector<int>>(n, vector<int>(n));
	FOR(i, n) {
		FOR(j, n) {
			cin >> floidDist[i][j];
		}
	}
	floid();
	
	cout << solution(startPlanet);

	return 0;
}