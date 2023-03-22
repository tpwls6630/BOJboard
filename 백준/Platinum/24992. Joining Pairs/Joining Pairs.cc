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
long long border(long long x, long long y) {
	if (y == 0) {
		return x;
	}
	else if (y == h) {
		return 2 * w + h - x;
	}
	else if (x == w) {
		return w + y;
	}
	else if (x == 0) {
		return 2 * w + 2 * h - y;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	cin >> w >> h >> n;

	map<long long, int> bor;
	FOR(i, n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int b1 = border(x1, y1), b2 = border(x2, y2);
		if (b1 == -1 || b2 == -1) continue;
		bor.insert({ b1,i });
		bor.insert({ b2,i });
	}

	stack<int> bracket;

	for (auto iter = bor.begin(); iter != bor.end(); iter++) {
		if (!bracket.empty()) {
			if (bracket.top() == iter->second) { bracket.pop(); }
			else bracket.push(iter->second);
		}
		else bracket.push(iter->second);
	}

	
	if (bracket.empty()) cout << "Y";
	else cout << "N";


	return 0;
}