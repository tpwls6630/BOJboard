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

long long w, h;
int n;
int border(int x, int y) {
	if (y == 0) {
		return x - w - h;
	}
	else if (y == h) {
		return w - x;
	}
	else if (x == w) {
		return y - h;
	}
	else if (x == 0) {
		return w + h - y;
	}
	return INT_MAX;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> w >> h >> n;

	vector<pair<int,int>> bor;
	FOR(i, n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int b1 = border(x1, y1), b2 = border(x2, y2);
		if (b1 == INT_MAX || b2 == INT_MAX) continue;
		bor.push_back({ b1,i });
		bor.push_back({ b2,i });
	}

	sort(all(bor));
	stack<int> bracket;

	for (auto iter = bor.begin(); iter != bor.end(); iter++) {
		if (!bracket.empty() && bracket.top() == iter->second) { bracket.pop(); }
		else bracket.push(iter->second);
	}

	
	if (bracket.empty()) cout << "Y";
	else cout << "N";


	return 0;
}