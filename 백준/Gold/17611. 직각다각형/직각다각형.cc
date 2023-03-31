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
#include <array>
//#include <bitset>
//#include <format>
#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, int>> dot(n),x,y;
	
	FOR(i, n) {
		cin >> dot[i].first >> dot[i].second;
		if (i > 0) {
			if (dot[i].first == dot[i - 1].first) { // x좌표가 같음 -> y축에 평행한 선분
				y.push_back({ max(dot[i].second, dot[i - 1].second),-1 });
				y.push_back({ min(dot[i].second, dot[i - 1].second),1 });
			}
			else { // x축에 평행한 선분
				x.push_back({ max(dot[i].first, dot[i - 1].first),-1 });
				x.push_back({ min(dot[i].first, dot[i - 1].first),1 });
			}
		}
	}
	if (dot[n-1].first == dot[0].first) {
		y.push_back({ max(dot[n-1].second, dot[0].second),-1 });
		y.push_back({ min(dot[n-1].second, dot[0].second),1 });
	}
	else {
		x.push_back({ max(dot[n-1].first, dot[0].first),-1 });
		x.push_back({ min(dot[n-1].first, dot[0].first),1 });
	}

	sort(all(x)); sort(all(y));

	int mx = 0, my = 0, xsum = 0, ysum = 0;

	for (auto e : x) {
		xsum += e.second;
		mx = max(mx, xsum);
	}
	for (auto e : y) {
		ysum += e.second;
		my = max(my, ysum);
	}

	cout << max(mx, my);

	return 0;
}