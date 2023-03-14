#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>
//#include <tuple>
//#include <stack>
//#include <array>
//#include <format>
#include <array>

#define llong long long
#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)

using namespace std;

vector<int> parent;

struct edge {
	int a , b;
	double d;
	edge() : a(0), b(0), d(0) {}
	edge(int A, int B, double D) : a(A), b(B), d(D) {}
	bool operator<(edge e) {
		return d < e.d;
	}
};

double dist(array<int,3> a1, array<int,3> a2) {
	return sqrt(pow(a1[0] - a2[0],2) + pow(a1[1] - a2[1],2)) - (double)a1[2] - (double)a2[2];
}

int Find(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int a, int b) {
	int A = Find(a), B = Find(b);
	if (A == B) return false;
	parent[A] = B;
	return true;

}

void mst(vector<edge>& E, int n) {
	parent = vector<int>(n + 1, -1);
	for (auto e : E) {
		Union(e.a, e.b);
		if (Find(0) == Find(n)) {
			cout << max((double)(0), e.d / 2) << "\n";
			return;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed;
	cout.precision(7);
	
	int T;
	cin >> T;
	while (T--) {
		int w, n; cin >> w >> n;
		vector<edge> E((n + 2) * (n + 1) / 2);
		int e = 0;
		vector<array<int, 3>> sensor(n);
		E[e++] = { 0,n + 1,(double)w };
		for(int i = 1; i <= n;i++) {
			int x, y, r;
			cin >> x >> y >> r;
			sensor[i - 1] = { x,y,r };
			E[e++] = { 0,i,(double)(x-r) };
			E[e++] = { n + 1,i,(double)(w - x - r) };
			for (int j = i - 1; j > 0; j--) {
				E[e++] = { i,j,dist(sensor[i - 1], sensor[j - 1]) };
			}
		}
		sort(all(E));
		mst(E, n+1);
	}
	
	return 0;
 }