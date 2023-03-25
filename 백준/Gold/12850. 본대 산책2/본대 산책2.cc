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

int n , d;
const int mod = 1'000'000'007;
vector<vector<int>> tgod;

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

void sq() {
	int p = d;
	vector<vector<int>> I(n, vector<int>(n, 0));
	FOR(i, n) I[i][i] = 1;
	while (p) {
		if (p % 2) {
			I = I * tgod;
		}
		tgod = tgod * tgod;
		p >>= 1;
	}
	tgod = I;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	n = 8;

	tgod = vector<vector<int>>(n, vector<int>(n, 0));

	tgod[0][1] = 1;
	tgod[0][2] = 1;
	tgod[1][2] = 1;
	tgod[1][3] = 1;
	tgod[2][3] = 1;
	tgod[2][4] = 1;
	tgod[3][4] = 1;
	tgod[3][5] = 1;
	tgod[4][5] = 1;
	tgod[4][6] = 1;
	tgod[5][7] = 1;
	tgod[6][7] = 1;

	tgod[1][0] = 1;
	tgod[2][0] = 1;
	tgod[2][1] = 1;
	tgod[3][1] = 1;
	tgod[3][2] = 1;
	tgod[4][2] = 1;
	tgod[4][3] = 1;
	tgod[5][3] = 1;
	tgod[5][4] = 1;
	tgod[6][4] = 1;
	tgod[7][5] = 1;
	tgod[7][6] = 1;

	cin >> d;
	sq();

	cout << tgod[0][0];

	return 0;
}