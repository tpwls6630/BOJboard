#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
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

    int n, m;
    cin >> n >> m;
    vector<int> memUsage(n + 1, 0), cost(n + 1, 0);
    int maxCost = 0;
    FOR(i, n)
    {
        cin >> memUsage[i + 1];
    }
    FOR(i, n)
    {
        cin >> cost[i + 1];
        maxCost += cost[i + 1];
    }

    vector<int> dp(maxCost + 1, 0);
    for (int bound = 1; bound <= n; ++bound)
    {
        for (int c = maxCost; c >= cost[bound]; --c)
        {
            dp[c] = max(dp[c], dp[c - cost[bound]] + memUsage[bound]);
        }
    }

    int ans = maxCost;
    for (int c = maxCost; c >= 0; --c)
    {
        if (dp[c] >= m)
            ans = c;
    }

    cout << ans;
    return 0;
}