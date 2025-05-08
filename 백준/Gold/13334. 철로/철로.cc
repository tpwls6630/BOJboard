#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iomanip>
#include "stdlib.h"
using namespace std;
#define FOR(_i, _x) for (int _i = 0; _i < _x; _i++)
#define PI 3.14159265358979323846
#define ll long long

typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    cin >> n;
    vector<pii> points(n); // {end, start}
    FOR(i, n)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            swap(a, b);
        }
        points[i] = {b, a};
    }
    cin >> d;
    sort(points.begin(), points.end());

    int max_lines = 0;
    priority_queue<int> pq; // {start}
    for (auto p : points)
    {
        int end = p.first;
        if (end - p.second <= d)
        {
            pq.push(-p.second);
        }

        while (!pq.empty() && end - (-pq.top()) > d)
        {
            pq.pop();
        }
        max_lines = max(max_lines, (int)pq.size());
    }

    cout << max_lines;

    return 0;
}