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

    int n;
    cin >> n;

    vector<int> matricies(n + 1);
    int a, b;
    FOR(i, n - 1)
    {

        cin >> a >> b;
        matricies[i] = a;
    }

    cin >> a >> b;
    matricies[n - 1] = a;
    matricies[n] = b;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case : (i-th matrix) x ((i+1)-th matrix)
    for (int i = 0; i < n - 1; ++i)
    {
        int p = matricies[i], q = matricies[i + 1], r = matricies[i + 2];
        dp[i][i + 1] = p * q * r;
    }

    for (int l = n - 3; l >= 0; --l)
    {
        for (int r = l + 2; r < n; ++r)
        {
            dp[l][r] = INT32_MAX;
            for (int k = l; k < r; ++k)
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + matricies[l] * matricies[k + 1] * matricies[r + 1]);
            }
        }
    }

    cout << dp[0][n - 1];

    return 0;
}