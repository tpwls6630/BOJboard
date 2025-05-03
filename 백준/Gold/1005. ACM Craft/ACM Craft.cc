#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include "stdlib.h"
using namespace std;
#define FOR(_i, _x) for (int _i = 0; _i < _x; _i++)
// 위상정렬, 그래프 탐색(bfs)
int solution()
{
    int n, k, target;
    cin >> n >> k;
    vector<int> time(n + 1);
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> edge(n + 1);

    FOR(i, n)
    {
        cin >> time[i + 1];
    }

    FOR(i, k)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        indegree[b]++;
    }

    cin >> target;

    // 위상정렬
    queue<int> q;
    vector<int> result(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            result[i] = time[i];
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        int cur_time = result[cur];
        q.pop();

        for (int next : edge[cur])
        {
            result[next] = max(result[next], cur_time + time[next]);
            if (--indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    return result[target];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cout << solution() << '\n';
    }

    return 0;
}