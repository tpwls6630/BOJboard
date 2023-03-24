#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long sum = 0, n; cin >> n;
	vector<long long> dp(n + 1);
	dp[1] = 2; dp[2] = 7; sum = dp[1] + dp[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = ((sum + 1) * 2 + dp[i - 2]) % 1'000'000'007;
		sum = (sum + dp[i]) % 1'000'000'007;
	}
	cout << dp[n];
	return 0;
}