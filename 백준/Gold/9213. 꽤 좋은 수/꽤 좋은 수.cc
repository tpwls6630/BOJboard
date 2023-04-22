#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int,int>
#define ll long long
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)

using namespace std;
//########################################################################//

vector<ll> bad;

void generateBad() {
	for (int i = 2; i <= 1000; i++) {
		if (i * i <= 1000000) bad[i * i] -= i;
		for (int j = i * i; j <= 1000000; j = j + i) {
			bad[j] += i + j / i;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	bad = vector<ll>(1000001, 1);
	
	generateBad();
	for (int i = 2; i <= 1000000; i++) bad[i] = abs(bad[i] - i);
	
	int start, end, badness;
	int T = 0;
	while (cin >> start >> end >> badness) {
		if (start == 0 && end == 0 && badness == 0) break;
		T++;
		int cnt = 0;
		for (int i = start; i <= end; i++)
			if (bad[i] <= badness) cnt++;

		cout << "Test " << T << ": " << cnt << "\n";
	}
	return 0;
}
