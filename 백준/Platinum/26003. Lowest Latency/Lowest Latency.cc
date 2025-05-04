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

typedef array<double, 3> point;

double Dist(point a, point b)
{
    return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2) + pow(a[2] - b[2], 2));
}
// 최근접 점 쌍 찾기

double Find_min_dist(vector<point> &points_by_x, vector<point> &points_by_y)
{
    if (points_by_x.size() <= 3)
    {
        double min_dist = INFINITY;
        for (int i = 0; i < points_by_x.size(); i++)
        {
            for (int j = i + 1; j < points_by_x.size(); j++)
            {
                min_dist = min(min_dist, Dist(points_by_x[i], points_by_x[j]));
            }
        }
        return min_dist;
    }

    // 점들을 절반으로 쪼개기
    int mid = points_by_x.size() / 2;
    point mid_point = points_by_x[mid];

    vector<point> points_by_x_left(points_by_x.begin(), points_by_x.begin() + mid);
    vector<point> points_by_x_right(points_by_x.begin() + mid, points_by_x.end());

    vector<point> points_by_y_left;
    vector<point> points_by_y_right;

    for (int i = 0; i < points_by_y.size(); i++)
    {
        if (points_by_y[i][0] < mid_point[0])
        {
            points_by_y_left.push_back(points_by_y[i]);
        }
        else
        {
            points_by_y_right.push_back(points_by_y[i]);
        }
    }

    double dl = Find_min_dist(points_by_x_left, points_by_y_left);
    double dr = Find_min_dist(points_by_x_right, points_by_y_right);
    double d = min(dl, dr);

    vector<point> strip;
    for (int i = 0; i < points_by_y.size(); i++)
    {
        if (abs(points_by_y[i][0] - mid_point[0]) < d)
        {
            strip.push_back(points_by_y[i]);
        }
    }

    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = i + 1; j < strip.size() && (strip[j][1] - strip[i][1]) < d; j++)
        {
            d = min(d, Dist(strip[i], strip[j]));
        }
    }

    return d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<point> points_by_x(n);
    vector<point> points_by_y(n);

    FOR(i, n)
    {
        cin >> points_by_x[i][0] >> points_by_x[i][1] >> points_by_x[i][2];
        points_by_y[i] = points_by_x[i];
    }

    // x축 방향으로 정렬
    sort(points_by_x.begin(), points_by_x.end(), [](point a, point b)
         { return a[0] < b[0]; });

    // y축 방향으로 정렬
    sort(points_by_y.begin(), points_by_y.end(), [](point a, point b)
         { return a[1] < b[1]; });

    cout << fixed << setprecision(10) << Find_min_dist(points_by_x, points_by_y);
    return 0;
}