#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
//#include <tuple>
#include <stack>
//#include <array>
//#include <format>

#define llong long long
#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)

using namespace std;

int n, m;
vector<int> p,h;

int Find(int x) {
	if (p[x] == -1)return x;
	return p[x] = Find(p[x]);
}

int Union(int a, int b) {
	int A = Find(a), B = Find(b);
	if (A == Find(b)) return false;
	int ret = h[A] + h[B];
	h[B] += h[A];
	p[A] = B;
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	p = vector<int>(n + 1, -1);
	h = vector<int>(n + 1, 1);
	vector<vector<int>> E(n+1,vector<int>());

	while (m--) {
		int a, b;
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	stack<int> stac;
	vector<bool> ans(n + 1), checked(n+1,false);
	int sum = 0;

	FOR(i,n) {
		int c; cin >> c;
		stac.push(c);
	}
	checked[stac.top()] = true;
	int an = n;
	ans[an--] = false; ans[an--] = true;
	++sum;
	stac.pop();

	while (!stac.empty()) {
		int cur = stac.top();
		++sum;
		checked[cur] = true;
		stac.pop();
		for (auto e : E[cur]) {
			if (checked[e]) {
				Union(cur, e);
			}
		}
		if (h[Find(cur)] == sum) ans[an--] = true;
		else ans[an--] = false;
		
	}

	for (auto e : ans) {
		if (e) cout << "CONNECT" << "\n";
		else cout << "DISCONNECT" << "\n";
	}


	return 0;
 }
