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

int n, k;
const int M = 100'000'000;
int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();

	cin >> n >> k;
	vector<int> dp(n + 1, M);

	dp[0] = 0;
	FOR(i, n + 1) {
		if (i + 1 < n + 1) {
			dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		}
		if (i + i / 2 < n + 1) {
			dp[i + i / 2] = min(dp[i + i / 2], dp[i] + 1);
		}
	}
	if (dp[n] <= k) cout << "minigimbob";
	else cout << "water";
	return 0;
}