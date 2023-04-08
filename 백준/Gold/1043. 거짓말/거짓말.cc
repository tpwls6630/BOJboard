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

int n, m;
vector<int> parent;
vector<bool> lie, lieparty;

int f(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = f(parent[x]);
}

bool u(int a, int b) {
    int A = f(a), B = f(b);
    if (A != B) {
        if (lieparty[A]) swap(A, B);
        parent[A] = B;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    int lier;
    cin >> lier;
    parent = vector<int>(m,-1);
    lie = vector<bool>(n + 1,false);
    lieparty = vector<bool>(m, false);
    vector<pair<int,int>> E;
    vector<vector<int>> party(m);
    while (lier--) {
        int temp;
        cin >> temp;
        lie[temp] = true;
    }
    FOR(i, m) {
        int c;
        cin >> c;
        FOR(k,c) {
            int temp; cin >> temp;
            party[i].push_back(temp);
            for (int j = i - 1; j >= 0; j--) {
                for (auto e : party[j]) {
                    if (e == temp) {
                        E.push_back({ i, j });
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < m;i++) {
        for (auto e : party[i]) {
            if (lie[e]) {
                lieparty[i] = true;
                break;
            }
        }
    }
    
    for (auto e : E) {
        u(e.first, e.second);
    }
    for (int i = 0; i < m; i++) {
        if (lieparty[f(i)]) lieparty[i] = true;
    }
    int ans = 0;
    for (auto e : lieparty)
        if (!e) ans++;
    cout << ans;

}