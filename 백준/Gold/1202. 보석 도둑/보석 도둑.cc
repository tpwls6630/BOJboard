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

struct comp
{
    bool operator()(pair<int, int> &p1, pair<int, int> &p2)
    {
        if (p1.second != p2.second)
            return p1.second < p2.second;
        else
        {
            return p1.first > p2.first;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cout.tie();
    cin.tie();

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> jewerly;
    FOR(i, n)
    {
        int m, v;
        cin >> m >> v;
        jewerly.push_back(*(new pair<int, int>(m, v)));
    }

    vector<int> backpacks(k);
    FOR(i, k)
    cin >> backpacks[i];

    sort(all(backpacks));
    sort(all(jewerly));

    int idx = 0;
    ull ans = 0;
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        while (idx < n && jewerly[idx].first <= backpacks[i])
        {
            pq.push(jewerly[idx++].second);
        }
        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
    return 0;
}