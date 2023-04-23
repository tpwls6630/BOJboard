#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int,int>
#define ll long long
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)

using namespace std;
//########################################################################//

int n, m;
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

	cin >> n >> m;
	vector<vector<int>> friends(n + 1, vector<int>());
	vector<vector<int>> enemy(n + 1, vector<int>());
	parent = vector<int>(n + 1, -1);
	FOR(i, m) {
		char c; int a, b;
		cin >> c >> a >> b;
		if (c == 'F') {
			friends[a].push_back(b);
			friends[b].push_back(a);
		}
		else {
			enemy[a].push_back(b);
			enemy[b].push_back(a);
		}
	}

	int cnt = 0;
	FOR(i, n) {
		for (auto fs : friends[i]) {
			if (u(i, fs)) cnt++;
		}
		for (auto es : enemy[i]) {
			for (auto eses : enemy[es]) {
				if (u(i, eses))cnt++;
			}
		}
	}

	cout << n - cnt;

	return 0;
}
