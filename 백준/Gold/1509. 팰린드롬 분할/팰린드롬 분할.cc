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

    string str;
    cin >> str;

    int n = str.size();

    vector<vector<bool>> pal(n + 1, vector<bool>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        pal[i][i] = 1;
    }

    for (int i = 1; i < n; i++)
        if (str[i - 1] == str[i]) pal[i][i + 1] = 1;

    for (int l = 3; l <= n; l++) {
        for (int s = 1; s <= n - l + 1; s++) {
            int e = s + l - 1;
            if (str[s - 1] == str[e - 1]) pal[s][e] = pal[s + 1][e - 1];
        }
    }

    vector<int> dp(n + 1, 2501);
    dp[0] = 0;
    for (int e = 1; e <= n; e++) {
        for (int s = 1; s <= e; s++) {
            if (pal[s][e]) {
                dp[e] = min(dp[e], dp[s - 1] + 1);
            }
            else {
                dp[e] = min(dp[e], dp[e - 1] + 1);
            }
        }
    }
    cout << dp[n];
    return 0;
}