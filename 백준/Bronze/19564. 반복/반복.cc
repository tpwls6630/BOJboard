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
    string s;
    cin >> s;
    int len = s.length();
    char last = 'z';
    int cnt = 0;
    for (char c : s)
    {
        if (c <= last)
        {
            ++cnt;
                }
        last = c;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cout << solution();

    return 0;
}