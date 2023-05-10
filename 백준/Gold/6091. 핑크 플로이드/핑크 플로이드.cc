#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#define all(x) x.begin(), x.end()
#define FOR(X,N) for(int X = 0; X < N; ++X)
#define ll long long
#define pii pair<int,int>

#define mat vector<vector<int>>
using namespace std;
//############################################################################

int n;
const int MAXNODE = 1024;
vector<int> parent(MAXNODE, -1);

int f(const int x) {
	if (parent[x] == -1) return x;
	return parent[x] = f(parent[x]);
}

bool u(int a, int b) {
	int A = f(a), B = f(b);
	if (A == B) return false;
	parent[A] = B;
	return true;
}

void mst(vector<array<int,3>>& sortedAdj) {
	int cnt = 0;
	vector<vector<bool>> adj(n, vector<bool>(n, false));
	vector<int> numAdj(n, 0);
	for (auto [w, a, b] : sortedAdj) {
		if (u(a, b)) {
			++cnt;
			adj[a][b] = true;
			adj[b][a] = true;
			++numAdj[a];
			++numAdj[b];
		}
		if (cnt == n - 1) break;
	}
	FOR(i, n) {
		cout << numAdj[i] << ' ';
		FOR(j, n) {
			if (adj[i][j]) cout << j + 1 << ' ';
		}
		cout << "\n";
	}

	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();

	cin >> n;
	vector<array<int, 3>> adj;
	FOR(i, n - 1) {
		FOR(j, n - 1 - i) {
			int dist; cin >> dist;
			adj.push_back({ dist, i, i + j + 1});
		}
	}

	sort(all(adj));

	mst(adj);
	return 0;
}