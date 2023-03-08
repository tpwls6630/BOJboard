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

#define llong long long
#define vi vector<int> 
#define mat vector<vi> 
#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)

using namespace std;

mat r, l;
int n;
int psum(int x, int y, int d) {
	int rp = r[y - x + n - 1][min(x, y) + d];
	if (min(x, y) != 0) {
		rp -= r[y - x + n - 1][min(x, y) - 1];
	}
	int lp = l[2 * n - 2 - x - y - d][min(x + d, n - 1 - y)];
	if (min(x, n - 1 - y - d) != 0) {
		lp -= l[2 * n - 2 - x - y - d][min(x, n - 1 - y - d) - 1];
	}

	return rp - lp;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	r = mat(2 * n - 1, vi(n)); l = mat(2 * n - 1, vi(n));

	FOR(j, n) {
		FOR(i, n) {
			int temp; cin >> temp;
			if (i > 0 && j > 0) {
				r[i - j + n - 1][min(i,j)] = r[i - j + n - 1][min(i, j) - 1] + temp;
			}
			else {
				r[i - j + n - 1][0] = temp;
			}
			if (n - 1 - i > 0 && j > 0) {
				l[2 * n - 2 - i - j][min(n - 1 - i, j)] = l[2 * n - 2 - i - j][min(n - 1 - i, j) - 1] + temp;
			}
			else {
				l[2 * n - 2 - i - j][0] = temp;
			}
		}
	}

	int ret = -1e9;

	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < n; y1++) {
			for (int d = 1; x1 + d < n && y1+d < n; d++) {
				ret = max(ret, psum(x1,y1,d));
			}
		}
	}

	cout << ret;

	return 0;
 }
