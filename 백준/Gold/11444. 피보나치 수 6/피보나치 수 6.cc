#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
//#include <string>
//#include <tuple>
//#include <stack>
#include <array>
//#include <format>
#define INT_MAX 2147483647
#define LLONG_MAX 9'223'372'036'854'775'807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; ++VAR)
using namespace std;
//#######################################################

const long long M = 1'000'000'007;
vector<vector<long long>> fibonachi(vector<vector<long long>> &v1, vector<vector<long long>> &v2) {
    return { {(v1[0][0]*v2[0][0] + v1[0][1]*v2[1][0]) % M,(v1[0][0] * v2[0][1] + v1[0][1] * v2[1][1]) % M},{(v1[1][0] * v2[0][0] + v1[1][1] * v2[1][0]) % M,(v1[1][0] * v2[0][1] + v1[1][1] * v2[1][1]) % M}};
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    long long n; cin >> n;

    int i = 0;
    vector<vector<vector<long long>>> fibo;
    fibo.push_back({ {1,1},{1,0} });
    while (((long long)1 << i) < n) {
        
        fibo.push_back(fibonachi(fibo[i], fibo[i]));
        ++i;
    }

    vector<vector<long long>> ans = { {1,0},{0,1} };
    for (int i = 0; ((long long)1 << i) <= n; i++) {
        if (((long long)1 << i) & n) {
            ans = fibonachi(ans, fibo[i]);
        }
    }

    cout << ans[0][1];
    return 0;
}