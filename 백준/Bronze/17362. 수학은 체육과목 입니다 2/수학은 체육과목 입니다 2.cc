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

int n;

int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();

	cin >> n;
	n--;
	n %= 8;
	if (n >= 5) {
		cout << (8 - n) % 5 + 1;
	}
	else {
		cout << n % 5 + 1;
	}

	return 0;
}