#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define pii pair<int,int>
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//

ll l, r;
int maxPrimeOffset;
vector<bool> squareNoNo;
vector<bool> prime;
void generatePrime() {

	for (int i = 2; i <= (int)sqrt(maxPrimeOffset); i++) {
		if (!prime[i]) continue;
		for (int j = i * i; j < maxPrimeOffset; j += i) {
			prime[j] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> l >> r;
	maxPrimeOffset = (int)sqrt(r) + 2;
	squareNoNo = vector<bool>(r - l + 1, true);
	prime = vector<bool>(maxPrimeOffset, true);

	generatePrime();

	for (ll i = 2; i < maxPrimeOffset; i++) {
		if (!prime[i]) continue;
		ll start = (l - 1) / (i * i) + 1; //ceil : 0.7 -> 1, 1 -> 1, 0.1 -> 1
		for (; start * i * i <= r; start++) {
			squareNoNo[start * i * i - l] = false;
		}
	}

	int ans = 0;
	for (auto s : squareNoNo) {
		if (s) ans++;
	}

	cout << ans;
	
	return 0;
}