#include <iostream>
#include <vector>


#define pii pair<int,int>
#define ll long long
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)

using namespace std;
//########################################################################//



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int asum = 0;
	vector<int> cnt(m, 0);
	FOR(i, n) {
		int temp;
		cin >> temp;
		asum = (asum + temp) % m;
		++cnt[asum];
	}

	ll ans = 0;
	ans += ((ll)cnt[0] * (cnt[0] + 1)) / 2;
	for (int r = 1; r < m; r++) {
		ans += ((ll)cnt[r] * (cnt[r] - 1)) / 2;
	}
	cout << ans;

	return 0;
}
