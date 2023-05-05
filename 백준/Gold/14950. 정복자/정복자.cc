#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <array>
#define pii pair<int,int>
#define ll long long
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)

using namespace std;
//########################################################################//

vector<int> parent;
int n,m,inc;
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

ll mst(vector<array<int,3>> &adj) {
	ll ret = 0, increase = 0;
	int cnt = 0;
	for (auto e : adj) {
		auto [w, a, b] = e;
		if (u(a, b)) {
			ret += w;
			ret += increase;
			increase += inc;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> inc;

	parent = vector<int>(n + 1, -1);
	vector<array<int, 3>> adj;
	while (m--) {
		int a, b, w;
		cin >> a >> b >> w;
		adj.push_back({ w,a,b });
	}

	sort(all(adj));

	ll ans = mst(adj);

	cout << ans;
	return 0;
}
