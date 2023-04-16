#include <algorithm>
#include <iostream>
#include <vector>
//#include <queue>
//#include <cmath>
//#include <cstring>
#include <string>
//#include <sstream>
//#include <stack>
//#include <typeinfo>
//#include <array>
//#include <bitset>
//#include <format>
//#include <set>

#define pii pair<int,int>
#define ll long long
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)



using namespace std;
//########################################################################//

const int INF = 100000;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	

	vector<vector<bool>> bulb(10, vector<bool>(10));

	FOR(i, 10) {
		string temp; cin >> temp;
		FOR(j, 10) {
			bulb[i][j] = temp[j] == 'O' ? 1 : 0;
		}
	}

	int ans = INF;
	pair<int, int> d[5] = { {-1,0},{1,0},{0,1},{0,-1},{0,0} };
	for (int c = 0; c < (1 << 10); c++) {
		vector<vector<bool>> temp(bulb);
		int sum = 0;
		FOR(j, 10) {
			if (c & (1 << j)) {
				sum++;
				for (auto e : d) {
					int ni = e.first, nj = j + e.second;
					if (ni < 0 || ni > 9 || nj < 0 || nj > 9) continue;
					temp[ni][nj] = !temp[ni][nj];
				}
			}
		}

		FOR(i, 9) {
			FOR(j, 10) {
				if (temp[i][j]) {
					sum++;
					for (auto e : d) {
						int ni = i + e.first + 1, nj = j + e.second;
						if (ni < 0 || ni > 9 || nj < 0 || nj > 9) continue;
						temp[ni][nj] = !temp[ni][nj];
					}
				}
			}
		}

		int valid = true;
		FOR(j, 10) if (temp[9][j]) { valid = false; break; }

		if (valid) ans = min(ans, sum);

	}
	
	if (ans == INF) cout << -1;
	else cout << ans;
	



	return 0;
}
