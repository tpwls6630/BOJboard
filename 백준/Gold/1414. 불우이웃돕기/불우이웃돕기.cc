#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define ll long long
#define pii pair<int,int>
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//

vector<int> parent;
int n;

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

int mst(vector<array<int, 3>>& adj ){

	int sum = 0;
	int cnt = 0;
	for (auto [d, a, b] : adj) {
		if (u(a, b)) {
			sum += d; ++cnt;
		}
		if (cnt == n - 1) break;
	}
	if (cnt != n - 1) return -1;
	return sum;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	

	cin >> n;

	int lengthOfLan = 0;
	vector<array<int, 3>> adj;
	parent = vector<int>(n, -1);
	FOR(i, n) {
		FOR(j, n) {
			char temp; cin >> temp;
			if (temp == '0') continue;
			int d = temp - 'a' + 1;
			if (d < 0) {
				d += -'A' + 'a' + 26;
			}
			lengthOfLan += d;
			if (i == j) continue;
			adj.push_back({ d,i,j });
		}
	}
	sort(all(adj));
	int canCutLan = mst(adj);
	if (canCutLan == -1) {
		cout << -1;
	}
	else {
		cout << lengthOfLan - canCutLan;
	}

	return 0;
}