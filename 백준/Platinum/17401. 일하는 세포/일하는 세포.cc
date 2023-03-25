#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
//#include <cstring>
//#include <string>
//#include <sstream>
//#include <stack>
//#include <typeinfo>
#include <array>
//#include <bitset>
//#include <format>

#define pii pair<int,int>
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//

int t,n,d;
const int mod = 1'000'000'007;
vector<vector<vector<int>>> map;

vector<vector<int>> operator* (vector<vector<int>>& ref1, vector<vector<int>>& ref2) {


	vector<vector<int>> ret(ref1.size(), vector<int>(ref1.size(), 0));

	for (int i = 0; i < ref1.size(); i++) {
		for (int j = 0; j < ref2[0].size(); j++) {
			int sum = 0;
			for (int k = 0; k < ref2.size(); k++) {
				sum = (((long long)ref1[i][k] * (long long)ref2[k][j]) % mod + sum) % mod;
			}
			ret[i][j] = sum;
		}
	}
	return ret;
}

vector<vector<int>> sq() {
	int p = d / t, r = d % t;
	vector<vector<int>> I(n, vector<int>(n, 0));
	FOR(i, n) I[i][i] = 1;
	while (p) {
		if (p % 2) {
			I = I * map[t - 1];
		}
		map[t - 1] = map[t - 1] * map[t - 1];
		p >>= 1;
	}
	if(r>0)
		I = I * map[r - 1];
	return I;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> t >> n >> d;

	map = vector<vector<vector<int>>>(t, vector<vector<int>>(n, vector<int>(n, 0)));

	FOR(i, t) {
		vector<vector<int>> temp(n, vector<int>(n, 0));
		int m; cin >> m;
		FOR(j, m) {
			int a, b, c;
			cin >> a >> b >> c;
			temp[a - 1][b - 1] = c;
		}
		if (i == 0) map[i] = temp;
		else {
			map[i] = map[i - 1] * temp;
		}
	}

	vector<vector<int>> ans = sq();
	for (auto v : ans) {
		for (auto e : v) cout << e << ' ';
		cout << "\n";
	}

	return 0;
}