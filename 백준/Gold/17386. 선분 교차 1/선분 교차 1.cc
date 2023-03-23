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



pair<int, int> operator-(pair<int, int>p1, pair<int, int>p2) {
	return { p1.first - p2.first, p1.second - p2.second };
}

int operator*(pair<int, int> p1, pair<int, int> p2) {
	return p1.first * p2.first + p1.second * p2.second;
}

struct line {
	pair<int, int> first, second;

	line() : first({ 0,0 }), second({ 0,0 }) {}

	pair<int, int> vec() {
		return	second - first;
	}
};



long long outer(pair<long long, long long> v1, pair<long long, long long> v2) {
	return (v1.first * v2.second - v1.second * v2.first);
}

bool cross(line l1, line l2) {
	long long o12 = outer(l1.vec(), l2.vec());
	if (o12 < 0)
		swap(l1, l2);

	pair<int, int> v[5];
	v[0] = v[4] = l2.first - l1.first;
	v[1] = l1.second - l2.first;
	v[2] = l2.second - l1.second;
	v[3] = l1.first - l2.second;

	//bool sameline = true;
	for (int i = 0; i < 4; i++) {
		//if (v[i].first == 0 && v[i].second == 0) return true;
		long long o = outer(v[i], v[i + 1]);
		//if (o != 0) sameline = false;
		if (outer(v[i], v[i + 1]) < 0) {
			return false;
		}
	}

	//if (sameline) if (v[0] * v[1] < 0 && v[1] * v[2] < 0 && v[2] * v[3] < 0 && v[3] * v[0] < 0) return false;
	

	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<line> l(2);
	FOR(i, 2)
		cin >> l[i].first.first >> l[i].first.second >> l[i].second.first >> l[i].second.second;

	if (cross(l[0], l[1])) cout << 1;
	else cout << 0;

	return 0;
}