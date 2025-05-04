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
array<ll, 3> Next(array<ll, 3> s)
{
    return {s[2], s[0], s[0] + s[1]};
}

char Find(const vector<array<ll, 3>> &counts, int level, ll pos)
{
    if (level == 1)
    {
        if (pos > 1)
            throw invalid_argument("level 1의 경우 pos는 1 이하여야 합니다.");
        return 'X';
    }
    if (level == 2)
    {
        if (pos == 1)
            return 'Y';
        else if (pos == 2)
            return 'Z';
        else
            throw invalid_argument("level 2의 경우 pos는 1 또는 2여야 합니다.");
    }
    if (level == 3)
    {
        if (pos == 1)
            return 'Z';
        else if (pos == 2)
            return 'X';
        else
            throw invalid_argument("level 3의 경우 pos는 1 또는 2여야 합니다.");
    }

    // level은 4 이상

    ll leftLength = counts[level - 3][0] + counts[level - 3][1] + counts[level - 3][2];
    ll rightLength = counts[level - 2][0] + counts[level - 2][1] + counts[level - 2][2];

    if (pos <= leftLength)
        return Find(counts, level - 3, pos);
    else
        return Find(counts, level - 2, pos - leftLength);
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    array<ll, 3> initial = {0L, 0L, 1L}; // 0단계는 "Z", 1단계는 "X"가 되도록 설계
    vector<array<ll, 3>> counts;

    int problemCase, level;
    cin >> problemCase >> level;
    for (int i = 0; i <= level; ++i)
    {
        counts.push_back(initial);
        initial = Next(initial);
    }
    switch (problemCase)
    {
    case 1:
        cout << counts[level][0] + counts[level][1] + counts[level][2] << '\n';
        break;
    case 2:
        ll pos;
        cin >> pos;
        cout << Find(counts, level, pos) << '\n';
        break;
    case 3:
        char t;
        cin >> t;
        if (t == 'X')
            cout << counts[level][0] << '\n';
        else if (t == 'Y')
            cout << counts[level][1] << '\n';
        else if (t == 'Z')
            cout << counts[level][2] << '\n';
        break;
    }
    return 0;
}