#include <algorithm>
#include <iostream>
#include <vector>

#define all(x) x.begin(), x.end()
#define FOR(X,N) for(int X = 0; X < N; ++X)
#define FOR1(X,N) for(int X = 1; X <= N; ++X)
#define ll long long
#define pii pair<int,int>
using namespace std;
//############################################################################
ll n, m;
const ll MAXTIME = 30 * (ll)2'000'000'000;
vector<ll> t;
bool calcTime(ll limit) {
	ll numPlayDone = 0;
	for (auto e : t) {
		numPlayDone += limit / e + 1;
	}
	if (numPlayDone >= n) {
		return true;
		
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();
	
	cin >> n >> m;
	t.resize(m);
	FOR(i, m) {
		cin >> t[i];
	}

	//search end time
	ll s = 0, e = MAXTIME, mid;
	ll ansTimeLimit = MAXTIME;
	while (s <= e) {
		mid = (s + e) / 2;
		if (calcTime(mid)) {
			ansTimeLimit = min(ansTimeLimit, mid);
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	//if end time(= ansTimeLimit) is 0, this mean the last child will play the nth attraction
	if (ansTimeLimit == 0) {
		cout << n;
		return 0;
	}

	//about (end time - 1) minute / {left} people lefted
	ll left = n;
	for (int ansPlay = 0; ansPlay < m; ansPlay++) {
		left -= (ansTimeLimit - 1) / t[ansPlay] + 1;
	}

	//with become {end time}, there are several attractions with playable, which can be decided by getting modular is 0 
	for (int ansPlay = 0; ansPlay < m; ansPlay++) {
		if (ansTimeLimit % t[ansPlay] == 0) {
			--left;
		}
		if (left == 0) {
			cout << ansPlay + 1;
			return 0;
		}
	}

	return 0;
}