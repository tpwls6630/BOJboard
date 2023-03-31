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



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> cnt(10001);
	int a;
	while (n--) {
		cin >> a;
		++cnt[a];
	}
	FOR(i, 10001) {
		FOR(j, cnt[i])
			cout << i << "\n";
	}

	return 0;
}