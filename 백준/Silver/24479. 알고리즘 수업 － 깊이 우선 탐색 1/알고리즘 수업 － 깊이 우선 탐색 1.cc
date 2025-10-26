#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

void dfs(int node_count, const vector<vector<int>> &adj, int start_node)
{

    vector<int> visited(node_count + 1, 0);
    stack<int> s;

    int visit_order = 1;

    s.push(start_node);

    while (!s.empty())
    {
        int c = s.top();
        s.pop();
        if (visited[c] != 0)
            continue;
        visited[c] = visit_order++;

        for (int i = adj[c].size() - 1; i >= 0; --i)
        {
            int neighbor = adj[c][i];
            if (visited[neighbor] == 0)
            {
                s.push(neighbor);
            }
        }
    }

    for (int i = 1; i <= node_count; ++i)
    {
        cout << visited[i] << "\n";
    }
}

int main()
{
    int n, e, s;
    cin >> n >> e >> s;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(n, adj, s);

    return 0;
}