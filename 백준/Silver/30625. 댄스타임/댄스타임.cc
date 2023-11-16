#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <string>
#include <map>
#include <queue>

#define all(x) x.begin(), x.end()
#define FOR(X,N) for(int X = 0; X < N; ++X)
#define FOR1(X,N) for(int X = 1; X <= N; ++X)
#define ll long long
#define pii pair<int,int>
using namespace std;
//############################################################################

const long long mod = 1'000'000'007;

long long power(long long x, int pow) {

	int p = pow;
	long long ans = 1;
	while (p > 0) {
		if (p & 1) {
			ans = (ans * x) % mod;
		}
		x = (x * x) % mod;
		p >>= 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();


	long long n, m;
	cin >> n >> m;

	long long forward = 0, backward = 0;

	FOR(i, n) {
		long long dance, direc;
		cin >> dance >> direc;

		backward += direc;
	}
	
	forward = n - backward;

	long long ret = 0;

	// 한번도 안틀렸을 때
	ret = power(m - 1, backward);

	// 앞에서 틀렸을 때
	ret = (ret + (forward * power(m - 1, backward + 1)) % mod) % mod;

	// 뒤에서 틀렸을 때
	ret = (ret + (backward * power(m - 1, backward - 1)) % mod) % mod;

	cout << ret;
	return 0;
}