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
#define LLONG_MAX 9223372036854775807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; ++VAR)
using namespace std;
//#######################################################

int r, c;
vector<vector<pair<int,int>>> parent;
vector<vector<int>> balls, height;

pair<int, int> Find(pair<int, int> x) {
    if (parent[x.first][x.second] == pair<int,int>{-1,-1}) return x;
    return parent[x.first][x.second] = Find(parent[x.first][x.second]);
}

bool Union(pair<int, int> u, pair<int, int> v) { // u -> v
    u = Find(u); v = Find(v);
    if (u == v) return false;
    balls[v.first][v.second] += balls[u.first][u.second];
    parent[u.first][u.second] = v;
    balls[u.first][u.second] = 0;
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;
    parent = vector<vector<pair<int, int>>>(r, vector<pair<int, int>>(c, { -1,-1 }));
    balls = vector<vector<int>>(r, vector<int>(c, 1));
    height = vector<vector<int>>(r, vector<int>(c, 0));

    FOR(i, r) {
        FOR(j, c) {
            cin >> height[i][j];
        }
    }

    vector<array<int, 4>> E;
    vector<pair<int, int>> D = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
    FOR(i, r) {
        FOR(j, c) {
            int ex = i, ey = j; int m = 0;
            for (auto d : D) {
                int ni = i + d.first, nj = j + d.second;
                if (ni < 0 || ni > r - 1 || nj<0 || nj >c - 1) continue;
                if (height[i][j] - height[ni][nj] > m) {
                    ex = ni; ey = nj; m = height[i][j] - height[ni][nj];
                }
            }
            if (m != 0) {
                E.push_back({ i,j,ex,ey });
            }
        }
    }

    for (auto e : E) {
        Union({ e[0],e[1] }, { e[2],e[3] });
    }

    for (auto v : balls) {
        for (auto e : v) {
            cout << e << ' ';
        }
        cout << "\n";
    }

    return 0;
}