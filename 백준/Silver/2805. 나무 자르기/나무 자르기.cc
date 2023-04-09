#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
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
#define ll long long
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)


using namespace std;
//########################################################################//

ll n, m;
vector<ll> tree;

ll cutTree(ll h) {
	ll ret = 0;
	for (auto t : tree) {
		ret += (t > h) ? t - h : 0;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;

	tree.resize(n);

	FOR(i, n) {
		cin >> tree[i]; 
	}


	ll s = 0, e = 1'000'000'000, mid;
	ll ans = 0;
	while (s <= e) {
		mid = (s + e) / 2;
		if (cutTree(mid) >= m) {
			ans = max(ans, mid);
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout << ans;

	return 0;
}