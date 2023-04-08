#include <algorithm>
#include <iostream>
#include <vector>
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
#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//

int n;
vector<vector<int>> dp;
vector<int> s, e;

int td(int idx, int rot) {
	
	rot %= 10;
	int& ret = dp[idx][rot];

	if (ret != -1) return ret;

	int cw = (e[idx] + 10 - (s[idx] + rot) % 10) % 10;
	int ccw = (10 - cw) % 10;

	if (idx == n) return ret = min(cw, ccw);
	return ret = min(cw + td(idx + 1, rot + cw), ccw + td(idx + 1, rot));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	
	
	string pre, des;
	cin >> n;
	cin >> pre >> des;
	s.resize(n+1); e.resize(n+1);
	s[0] = e[0] = 0;
	for (int i = 1; i <= n; i++){
		s[i] = pre[i-1] - '0';
		e[i] = des[i-1] - '0';
	}

	dp = vector<vector<int>>(n+1, vector<int>(10, -1));

	int ans = td(0, 0);

	cout << ans;


	return 0;
}