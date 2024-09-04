#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
//#include <set>
//#include <unordered_set>
//#include <sstream>
//#include <deque>
//#include <tuple>
//#include <stack>
//#include <unordered_map>
//#include <typeinfo>
//#include <array>
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

struct edge {
	int a, b, c;

	bool operator<(edge e) {
		return c < e.c;
	}
};

llong Find(vector<llong> &parent, const llong a) {
	if (parent[a] == -1) return a;
	return parent[a] = Find(parent, parent[a]);
}

bool Union(vector<llong> &parent, vector<llong> &height, llong a, llong b) {
	a = Find(parent, a); b = Find(parent, b);
	if (a == b) return false;

	if (height[a] < height[b])
		swap(a, b);
	parent[b] = a;

	if (height[a] == height[b]) height[a]++;
	return true;
}

int mst(vector<edge> &E) {

	vector<llong> parent(n, -1), height(n, 0);
	
	int ret = 0, cnt = 0;

	for (int i = 0; i < m; i++) {
		
		if (Union(parent, height, E[i].a, E[i].b)) {
			ret += E[i].c;
			cnt++;
		}
		if (cnt == n - 1) break;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	vector<edge> E(m);
	FOR(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		E[i].a = a - 1; E[i].b = b - 1; E[i].c = c;
	}

	sort(all(E));

	cout << mst(E);
	return 0;
 }
