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

int n, k, m;
vector<vector<bool>> tgod;

vector<vector<bool>> operator* (vector<vector<bool>> &ref1, vector<vector<bool>> &ref2) {
	vector<vector<bool>> ret(ref1.size(), vector<bool>(ref1.size(), 0));
	for (int i = 0; i < ref1.size(); i++) {
		for (int j = 0; j < ref2[0].size(); j++) {
			for (int k = 0; k < ref2.size(); k++) {
				ret[i][j] = ret[i][j] || (ref1[i][k] && ref2[k][j]);
			}
		}
	}
	return ret;
}

void sq() {
	int p = k;
	vector<vector<bool>> I(n, vector<bool>(n, 0));
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

	cin >> n >> k >> m;
	tgod = vector<vector<bool>>(n, vector<bool>(n,0));
	FOR(i, n) {
		int a, b; cin >> a >> b;
		tgod[i][a - 1] = 1;
		tgod[i][b - 1] = 1;
	}
	sq();

	FOR(i, m) {
		int s, e; cin >> s >> e;
		if (tgod[s - 1][e - 1]) cout << "death\n";
		else cout << "life\n";
	}

	return 0;
}