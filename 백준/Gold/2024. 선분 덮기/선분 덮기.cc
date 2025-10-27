#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

int solution()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;

    vector<pair<int, int>> lines;

    int MAX = 100002;
    while (MAX--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;

        lines.push_back({a, b});
    }

    sort(lines.begin(), lines.end());

    int left = 0;
    int index = 0;
    int maxRight = 0;
    int ans = 0;
    while (index < lines.size() && left < m)
    {
        while (index < lines.size() && lines[index].first <= left)
        {
            maxRight = max(maxRight, lines[index].second);
            ++index;
        }

        if (maxRight <= left)
        {
            return 0;
        }
        else
        {
            ++ans;
            left = maxRight;
        }
    }

    if (left < m)
        return 0;
    else
        return ans;
}

int main()
{
    cout << solution();

    return 0;
}