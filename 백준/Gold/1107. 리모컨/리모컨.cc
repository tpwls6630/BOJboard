#include <algorithm>
#include <iostream>
#include <vector>
//#include <queue>
//#include <cmath>
//#include <cstring>
#include <string>
//#include <sstream>
#include <stack>
//#include <typeinfo>
//#include <array>
//#include <bitset>
//#include <format>

#define pii pair<int,int>
#define ll long long
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)


using namespace std;
//########################################################################//

int digit;
vector<bool> btn;
int avail(int x) {
	if (x == 0 && btn[0] == false) {
		return -1;
	}
	if (x == 0) return 1;
	int p = 0;
	while (x) {
		int r = x % 10;
		if (btn[r] == false) return -1;
		p++;
		x /= 10;
	}
	return p;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int target;
	cin >> target;
	int broken;
	cin >> broken;
	btn = vector<bool>(10, true);
	FOR(i, broken) {
		int temp;
		cin >> temp;
		btn[temp] = false;
	}
	int ans = abs(target - 100);
	for (int x = 0; x <= 1'000'000; x++) {
		int p = avail(x);
		if (p == -1) continue;
		ans = min(ans, p + abs(target - x));
	}
	cout << ans;
	return 0;
}