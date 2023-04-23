#include <algorithm>
#include <iostream>
#include <vector>
#include <array>

#define pii pair<int,int>
#define ll long long
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)

using namespace std;
//########################################################################//

vector<int> parent;

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
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, q;
	cin >> n >> q;

	vector<array<int, 3>> woods(n);
	vector<array<int, 3>> line;
	vector<vector<int>> adj;
	parent = vector<int>(n + 1, -1);

	FOR(i, n) {
		cin >> woods[i][0] >> woods[i][1] >> woods[i][2];
		line.push_back({ woods[i][0], -1, i + 1 }); // add wood
		line.push_back({ woods[i][1], 1, i + 1 });  // delete wood
	}
	sort(all(line));

	vector<int> groups; int cnt = 0;
	for (auto [point, add, number] : line) {
		if (add == -1) {
			// add
			groups.push_back(number);
			++cnt;
		}
		else {
			//delete
			--cnt;
		}
		if (cnt == 0) {
			// joint is done
			adj.push_back(groups);
			groups = vector<int>(); // reset
		}
	}

	for (auto group : adj) {
		for (int i = 1; i < group.size(); i++) {
			u(group[i - 1], group[i]);
		}
	}

	while (q--) {
		int a, b;
		cin >> a >> b;

		if (f(a) == f(b)) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	
	return 0;
}
