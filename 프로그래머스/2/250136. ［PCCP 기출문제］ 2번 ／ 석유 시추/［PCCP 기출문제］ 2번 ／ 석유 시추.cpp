#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

vector<vector<int>> bfs(vector<vector<int>> &land)
{

    const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    queue<pii> q;
    int n = land.size();
    int m = land[0].size();

    vector<bool> visited(n * m, false);
    vector<vector<int>> ret;

    for (int i = 0; i < n * m; ++i)
    {

        if (visited[i])
            continue;

        int x = i / m;
        int y = i % m;
        q.push({x, y});
        visited[i] = true;

        bool isOil = (land[x][y] == 1);
        int oil = 0;
        int left = m - 1, right = 0;
        while (!q.empty())
        {
            pii cur = q.front();
            q.pop();

            if (isOil && (land[cur.first][cur.second] == 1))
            {
                ++oil;
                left = min(left, cur.second);
                right = max(right, cur.second);
            }

            for (int d = 0; d < 4; ++d)
            {
                int nx = cur.first + dir[d][0];
                int ny = cur.second + dir[d][1];
                if (nx >= n || nx < 0 || ny >= m || ny < 0)
                    continue;
                if (isOil ^ (land[nx][ny] == 1))
                    continue;
                if (!visited[nx * m + ny])
                {
                    visited[nx * m + ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        if (isOil)
        {
            ret.push_back({left, oil});
            ret.push_back({right + 1, -oil});
        }
    }
    return ret;
}

int solution(vector<vector<int>> land)
{

    vector<vector<int>> oilInfo = bfs(land);
    sort(oilInfo.begin(), oilInfo.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    int m = land[0].size();
    int optimalOil = 0;
    int oilSum = 0;
    vector<vector<int>>::iterator it = oilInfo.begin();
    for (int i = 0; i < m; ++i)
    {
        while (it != oilInfo.end() && (*it)[0] <= i)
        {
            oilSum += (*it)[1];
            it++;
        }

        optimalOil = max(optimalOil, oilSum);
    }

    return optimalOil;
}
