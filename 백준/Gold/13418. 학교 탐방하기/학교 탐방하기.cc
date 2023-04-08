#include <algorithm>
#include <iostream>
#include <vector>
//#include <format>
//#include <queue>
//#include <cmath>
#include <deque>
//#include <string>
//#include <tuple>
//#include <stack>
//#include <sstream>
//#include <map>
//#include <unordered_map>
//#include <array>


#define INT_MAX 2147483647
#define LLONG_MAX 9'223'372'036'854'775'807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; ++VAR)
using namespace std;
//#######################################################

int n, m;
vector<int> p;

struct edge {
	int a, b, d;

	edge() : a(0), b(0), d(0) {}
	edge(int A, int B, int D) : a(A), b(B), d(D) {}
	bool operator<(edge& ref) {
		return d > ref.d;
	}
};
int f(int x) {
	if (p[x] == -1) return x;
	return p[x] = f(p[x]);
}
bool u(int a, int b) {
	int A = f(a), B = f(b);
	if (A == B)return false;
	p[A] = B; return true;
}

int mst(vector<edge> &E, bool M) {
	p = vector<int>(n + 1, -1);
	if (M) {
		int sum = 0, cnt = 0;
		for(auto e : E) {
			if (u(e.a, e.b)) {
				sum += e.d;
				++cnt;
			}
			if (cnt == n - 1) break;
		}

		return sum;
	}
	else {
		int sum = 0, cnt = 0;
		for (int i = E.size() - 1; i >= 0;i--) {
			auto e = E[i];
			if (u(e.a, e.b)) {
				sum += e.d;
				++cnt;
			}
			if (cnt == n - 1) break;
		}

		return sum;
	}
	/*

	auto iter = E.begin(), iterend = E.end();
	if (M) {
		auto iter = E.rbegin(); 
		auto iterend = E.rend();
	}

	int sum = 0, cnt = 0;
	for (; iter != iterend; iter++) {
		if (u(iter->a, iter->b)) {
			sum += iter->d;
			++cnt;
		}
		if (cnt == n - 1) break;
	}

	return sum;*/
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	
	bool st;
	int a, b, c;
	cin >> a >> b >> st;
	
	vector<edge> E;

	FOR(i, m) {
		cin >> a >> b >> c;
		E.push_back({a,b,!c});
	}
	sort(all(E));

	int Mx = mst(E, 1) , mx = mst(E, 0);
	Mx += !st; mx += !st;
	cout << Mx * Mx - mx * mx;
	return 0;
}