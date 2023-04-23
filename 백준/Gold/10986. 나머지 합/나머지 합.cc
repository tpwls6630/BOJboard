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
	vector<int> remains(n);
	vector<int> asum(n, 0);
	FOR(i, n) {
		cin >> remains[i];
		remains[i] %= m;
		if (i == 0) asum[0] = remains[0];
		else asum[i] = (asum[i - 1] + remains[i]) % m;
	}
	vector<ll> cnt(m, 0);
	FOR(i, n) {
		++cnt[asum[i]];
	}
	ll ans = 0;
	ans += (cnt[0] * (cnt[0] + 1)) / 2;
	for (int r = 1; r < m; r++) {
		ans += (cnt[r] * (cnt[r] - 1)) / 2;
	}
	cout << ans;

	return 0;
}
