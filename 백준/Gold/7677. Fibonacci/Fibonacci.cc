#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int,int>
#define ll long long
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)

using namespace std;
//########################################################################//

const int MOD = 10000;

vector<vector<int>> operator*(vector<vector<int>> &v1, vector<vector<int>> &v2) {
	vector<vector<int>> ret = { {0,0},{0,0} };
	FOR(i, 2)
		FOR(j, 2)
			FOR(k, 2)
				ret[i][j] = (ret[i][j] + v1[i][k] * v2[k][j]) % MOD;

	return ret;
}

int fibonacci(int n) {
	if (n == 0) return 0;
	vector<vector<int>> mat = { {1,1},{1,0} }, ret = { {1,0},{0,1} };

	while (n) {
		if (n & 1) ret = ret * mat;
		mat = mat * mat;
		n >>= 1;
	}

	return ret[0][1];

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int power;
	while (cin >> power) {
		if (power == -1) break;
		cout << fibonacci(power) << "\n";
	}
	

	return 0;
}
