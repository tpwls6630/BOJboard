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
#define vv(TYPE) vector<vector<TYPE>>

using namespace std;
// ############################################################################

const int INF = 1'000'000'000;
vv(vector<int>) dp;
vv(int) edge;
int n;
int sol(int unvisitBit, int start, int end, int unvisitNum = n) {

    if (unvisitBit == 0) return 0;

    if (dp[start][end][unvisitBit] != -1) return dp[start][end][unvisitBit];
    int& ret = dp[start][end][unvisitBit];

    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (i == start) continue;
        if (unvisitNum != 1 && i == end) continue;
        int next = 1 << i;
        if (edge[start][i] == 0) continue;
        if (unvisitBit & next) {
            ans = min(ans, edge[start][i] + sol(unvisitBit - next, i, end, unvisitNum - 1));
        }
    }

    return ret = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie();
    cin.tie();

    cin >> n;
    edge = vv(int)(n, vector<int>(n));

    FOR(i, n)
        FOR(j, n)
        cin >> edge[i][j];

    int maxbit = (1 << n) - 1;
    dp = vv(vector<int>)(n, vv(int)(n, vector<int>(maxbit + 1, -1)));

    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, sol((1 << n) - 1, i, i));
    }
    cout << ans;
    return 0;
}