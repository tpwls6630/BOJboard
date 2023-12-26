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

    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> gadgets;
    FOR(i, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        while (c)
        {
            int bundle = c - (c >> 1);
            gadgets.push_back({a * bundle, b * bundle});
            c -= bundle;
        }
    }

    n = gadgets.size();

    vector<int> dp(m + 1, 0);

    for (int bound = 0; bound < n; ++bound)
    {
        for (int weight = m; weight >= gadgets[bound][0]; --weight)
        {
            dp[weight] = max(dp[weight], dp[weight - gadgets[bound][0]] + gadgets[bound][1]);
        }
    }

    cout << dp[m];

    return 0;
}