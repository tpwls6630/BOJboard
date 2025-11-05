#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int upperbound(long long x, long long r2)
{
    int l = 0, r = r2;
    long long mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (pow(x, 2) + pow(mid, 2) <= pow(r2, 2))
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return r;
}

int lowerbound(long long x, long long r1, long long r2)
{
    int l = 0, r = r2;
    long long mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (pow(x, 2) + pow(mid, 2) >= pow(r1, 2))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    return r;
}

long long solution(int r1, int r2)
{
    long long answer = 0;
    // x좌표 1이상, y좌표 0이상
    // 각 x좌표에 대해 lowerbound, upperbound를 구하기
    // upperbound - lowerbound만큼을 정답에 더하기
    // 4를 곱하기

    for (long long x = 1; x <= r2; ++x)
    {
        int col = upperbound(x, r2) - lowerbound(x, r1, r2);
        answer += col;
    }
    return answer * 4;
}