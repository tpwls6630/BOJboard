#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <string>
#include <map>
#include <queue>

#define all(x) x.begin(), x.end()
#define FOR(X,N) for(int X = 0; X < N; ++X)
#define FOR1(X,N) for(int X = 1; X <= N; ++X)
#define ll long long
#define pii pair<int,int>
using namespace std;
//############################################################################

int n, m, k;
vector<int> candy;
vector<int> candyMod;
vector<vector<int>> dp;
int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();

	cin >> n >> m >> k;
	candy = vector<int>(n);
	candyMod = vector<int>(k, -1); // j_th element means maximum candy mod k == j
	dp = vector<vector<int>>(m + 1, vector<int>(k, -1));
	FOR(i, n) {
		cin >> candy[i];
		candyMod[candy[i] % k] = max(candyMod[candy[i] % k], candy[i]);
	}
	FOR(i, k) {
		dp[0][i] = 0;
	}
	for (int box = 1; box <= m; box++) {
		if (box == 1) {
			FOR(i, k) {
				if (candyMod[i] != -1) dp[1][i] = candyMod[i];
			}
			continue;
		}

		for (int firstMod = 0; firstMod < k; firstMod++) {
			if (dp[box - 1][firstMod] == -1) continue;
			for (int secondMod = 0; secondMod < k; secondMod++) {
				if (candyMod[secondMod] == -1) continue;
				int nextMod = (firstMod + secondMod) % k;
				dp[box][nextMod] = max(dp[box][nextMod], dp[box - 1][firstMod] + candyMod[secondMod]);
			}
		}

	}

	int ret = 0;
	for (int sol = m; sol >= 0; sol--) {
		if (dp[sol][0] != -1) {
			ret = max(ret, dp[sol][0]);
		}
	}
	cout << ret;
	return 0;
}