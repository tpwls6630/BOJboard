#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <string>
#include <cstring>
#include <map>
#include <queue>

#define all(x) x.begin(), x.end()
#define FOR(X, N) for (int X = 0; X < N; ++X)
#define FOR1(X, N) for (int X = 1; X <= N; ++X)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
using namespace std;
// ############################################################################

int main()
{
    ios::sync_with_stdio(false);
    cout.tie();
    cin.tie();

    int n;
    cin >> n;
    vector<int> nums(n + 1, 0);
    FOR(i, n)
    cin >> nums[i + 1];

    ll dp[100][21];
    memset(dp, 0, sizeof(dp));
    dp[1][nums[1]] = 1;

    for (int numBound = 2; numBound < n; numBound++)
    {
        for (int res = 0; res <= 20; res++)
        {
            if (res - nums[numBound] >= 0)
            {
                dp[numBound][res] += dp[numBound - 1][res - nums[numBound]];
            }
            if (res + nums[numBound] <= 20)
            {
                dp[numBound][res] += dp[numBound - 1][res + nums[numBound]];
            }
        }
    }

    cout << dp[n - 1][nums[n]];
    return 0;
}