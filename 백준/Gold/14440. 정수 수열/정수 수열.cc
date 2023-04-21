//#include <algorithm>
#include <iostream>
#include <vector>
#include "stdio.h"
//#include <queue>
//#include <cmath>
//#include <cstring>
//#include <string>
//#include <sstream>
//#include <stack>
//#include <typeinfo>
//#include <array>
//#include <bitset>
//#include <format>

#define ll long long
#define pii pair<int,int>
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//

const ll MOD = 100;

ll x, y, a0, a1, n;

vector<vector<ll>> prod(vector<vector<ll>> &v1, vector<vector<ll>> &v2) {
	vector<vector<ll>> ret(2,vector<ll>(2,0));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ret[i][j] += v1[i][k] * v2[k][j];
			}
			ret[i][j] %= MOD;
		}
	}
	return ret;
}

int r(vector<vector<ll>> A, int n) {
	if (n == 0) {
		return a0;
	}
	vector<vector<ll>>  M = { {1,0},{0,1} };
	n--;
	while (n) {
		if (n & 1) {
			M = prod(M, A);
		}
		n >>= 1;
		A = prod(A, A);
	}
	return (M[0][0] * a1 + M[0][1] * a0) % MOD;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y >> a0 >> a1 >> n;
	vector<vector<ll>> A = { {x,y},{1,0} };
	
	cout.fill('0');
	cout.width(2);
	cout << r(A, n);
	return 0;
}