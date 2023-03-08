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


int n;
vector<vector<array<int, 2>>> node;
array<int, 2> bfs(int start) {

	queue<array<int, 2>> q;
	vector<bool> visited(n + 1, false);
	array<int, 2> m = { 0,0 };
	q.push({ start,0 });
	visited[start] = true;

	while (!q.empty()) {

		auto [cur, d] = q.front();
		q.pop();
		if (m[1] < d) m = { cur,d };
		for (auto e : node[cur]) {
			if (!visited[e[0]]) {
				q.push({ e[0],d + e[1] });
				visited[e[0]] = true;
			}
		}
	}

	return m;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	node = vector<vector<array<int, 2>>>(n + 1, vector<array<int, 2>>());

	FOR(i, n - 1) {
		int a,b,d; cin >> a>>b>>d;
		node[a].push_back({ b,d });
		node[b].push_back({ a,d });
		
	}

	cout << bfs(bfs(1)[0])[1];

	return 0;
}