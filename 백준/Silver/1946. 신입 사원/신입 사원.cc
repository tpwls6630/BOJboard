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

#define pii pair<int,int>
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)


using namespace std;
//########################################################################//

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<pii> emp(n);
		FOR(i, n) {
			cin >> emp[i].first >> emp[i].second;
		}
		sort(all(emp));
		int m = emp[0].second;
		int ret = 0;
		for (int i = 0; i < n; i++) {
			if (emp[i].second > m) continue;
			m = emp[i].second;
			ret++;
		}
		cout << ret << "\n";
	}

	return 0;
}