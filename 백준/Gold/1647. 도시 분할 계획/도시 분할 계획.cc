#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <string>
#include <cstring>
#include <map>
#include <queue>

#define all(x) x.begin(), x.end()
#define FOR(X, N) for (int X = 0; X < N; ++X)
#define FOR1(X, N) for (int X = 1; X <= N; ++X)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
using namespace std;
// ############################################################################

vector<int> parent;
int n, m;

int f(int x) {
    if (parent[x] == -1) return x;
    return parent[x] = f(parent[x]);
}

bool u(int a, int b) {
    int A = f(a), B = f(b);
    if (A == B) return false;
    parent[A] = B;
    return true;
}

int mst(vector<array<int,3>> &edge) {
    int cnt = 0;
    parent = vector<int>(n, -1);
    int sum = 0;
    for (auto [w, a, b] : edge) {
        if (cnt == n - 2) break;
        if (u(a, b)) {
            sum += w;
            cnt++;
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie();
    cin.tie();

    
    cin >> n >> m;

    vector<array<int, 3>> edge;
    FOR(i, m) {
        int a, b, w;
        cin >> a >> b >> w;
        edge.push_back({w,a-1,b-1});
    }

    sort(all(edge));

    cout << mst(edge);

    return 0;
}