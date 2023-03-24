#include <algorithm>
#include <iostream>
#include <vector>
//#include <format>
//#include <queue>
//#include <cmath>
//#include <deque>
//#include <string>
//#include <tuple>
#include <stack>
//#include <sstream>
#include <map>
//#include <unordered_map>
//#include <array>


#define INT_MAX 2147483647
#define LLONG_MAX 9'223'372'036'854'775'807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; ++VAR)
using namespace std;
//#######################################################

int l,n;

int border(int x, int y) {
	if (y == 0) {
		return x - 2*l;
	}
	else if (y == l) {
		return l - x;
	}
	else if (x == l) {
		return y - l;
	}
	else if (x == 0) {
		return 2*l - y;
	}
	return INT_MAX;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> l >> n;

	vector<pair<int, int>> bor;
	vector<vector<int>> color(n / 2);
	FOR(i, n) {
		int x, y, c;
		cin >> x >> y >> c;
		int b1 = border(x, y);
		if (b1 == INT_MAX) continue;
		color[c - 1].push_back(b1);
		bor.push_back({ b1,c - 1 });
	}

	sort(all(bor));
	stack<int> bracket;

	for (auto iter = bor.begin(); iter != bor.end(); iter++) {
		if (color[iter->second].size() == 1) continue;
		if (!bracket.empty() && bracket.top() == iter->second) { bracket.pop(); }
		else bracket.push(iter->second);
	}


	if (bracket.empty()) cout << "1";
	else cout << "0";
	cout << '%';

	return 0;
}