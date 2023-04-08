#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
//#include <sstream>
//#include <deque>
//#include <tuple>
#include <stack>
//#include <unordered_map>
//#include <typeinfo>
#include <array>
//#include <bitset>
//#include <format>

#define llong long long
#define vi vector<int> 
#define mat vector<vi> 
#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> m(3,0), M(3,0);
	vector<int> temp(3,0);
	while (n--) {
		int a[3];
		cin >> a[0] >> a[1] >> a[2];
		FOR(i, 3) {
			temp[i] = a[i] + m[i];
		}
		m[0] = min(temp[0], temp[1]);
		m[1] = min(temp[0], min(temp[1], temp[2]));
		m[2] = min(temp[1], temp[2]);
		FOR(i, 3) {
			temp[i] = a[i] + M[i];
		}
		M[0] = max(temp[0], temp[1]);
		M[1] = max(temp[0], max(temp[1], temp[2]));
		M[2] = max(temp[1], temp[2]);
	}

	cout << max(M[0], max(M[1], M[2])) << ' ' << min(m[0], min(m[1], m[2]));
	return 0;
}