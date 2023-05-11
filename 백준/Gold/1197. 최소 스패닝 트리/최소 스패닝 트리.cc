#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#define all(x) x.begin(), x.end()
#define FOR(X,N) for(int X = 0; X < N; ++X)
#define FOR1(X,N) for(int X = 1; X <= N; ++X)
#define ll long long
#define pii pair<int,int>
using namespace std;
//############################################################################

int n;
vector<int> p;
int f(int x) {
	if (p[x] == -1) return x;
	return p[x] = f(p[x]);
}

bool u(int a, int b) {
	if (f(a) == f(b)) return false;
	p[f(a)] = f(b);
	return true;
}

int mst(vector<array<int, 3>>& adj) {
	int cnt = 0, sum = 0;
	for (auto [w, a, b] : adj) {
		if (u(a, b)) {
			sum += w;
			++cnt;
		}
		if (cnt == n - 1) {
			break;
		}
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();

	int m;
	cin >> n >> m;
	p = vector<int>(n + 1, -1);
	vector<array<int, 3>> adj(m);
	FOR(i, m) FOR(j, 3) cin >> adj[i][2 - j];
	sort(all(adj));
	cout << mst(adj);

	return 0;
}