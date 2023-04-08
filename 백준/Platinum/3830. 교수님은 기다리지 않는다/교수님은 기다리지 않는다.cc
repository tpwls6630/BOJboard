#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
//#include <sstream>
//#include <deque>
//#include <tuple>
#include <stack>
//#include <unordered_map>
//#include <typeinfo>
#include <array>
//#include <bitset>
//#include <format>

#define llong long long
#define vi vector<int> 
#define mat vector<vi> 
#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;

int n, m;
vector<array<int, 2>> parent;

array<int, 2> Find(int x) {
	if (parent[x][0] == -1) return { x, 0 };
	auto [g, w] = Find(parent[x][0]);
	return parent[x] = {g, w + parent[x][1]};
}

bool Union(int light, int heavy, int w) {
	array<int, 2> L = Find(light), H = Find(heavy);
	if (L[0] == H[0]) return false;

	parent[L[0]] = { H[0], H[1] - L[1] + w };
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0) return 0;

		parent = vector<array<int, 2>>(n + 1, { -1,0 });

		while (m--) {
			string com; cin >> com;
			if (com == "?") {
				int a, b; cin >> a >> b;
				array<int, 2> A = Find(a), B = Find(b);
				if (A[0] != B[0]) { cout << "UNKNOWN" << "\n"; continue; }
				else {
					cout << A[1] - B[1] << "\n";
				}
			}
			else {
				int a, b, w; cin >> a >> b >> w;
				Union(a, b, w);
			}
		}
	}
	



	return 0;
}