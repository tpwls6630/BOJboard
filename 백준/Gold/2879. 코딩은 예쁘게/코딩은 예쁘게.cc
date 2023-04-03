#include <algorithm>
#include <iostream>
#include <vector>
//#include <queue>
#include <cmath>
//#include <cstring>
#include <string>
//#include <sstream>
#include <stack>
//#include <typeinfo>
#include <array>
//#include <bitset>
//#include <format>
#include <numeric>

#define pii pair<int,int>
#define IM 2'147'483'647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//

int n;
vector<int> diff;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	diff.resize(n + 1); diff[0] = 0;
	FOR(i, n) { int temp; cin >> temp; diff[i + 1] -= temp; }
	FOR(i, n) { int temp; cin >> temp; diff[i + 1] += temp; }
	int sum = 0, positive = 0;
	for (int i = 1; i <= n; i++) {
		
		if (diff[i] * positive > 0) {
			int dx = abs(diff[i]) - abs(diff[i - 1]);
			if (dx < 0) sum -= dx;
		}
		else {
			sum += abs(diff[i - 1]);
		}

		if (diff[i] == 0) positive = 0;
		else positive = diff[i] > 0 ? 1 : -1;
	}
	sum += abs(diff[n]);
	cout << sum;

	return 0;
}