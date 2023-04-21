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
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)


using namespace std;
//########################################################################//


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		queue<pii> printq;
		vector<int> prio(10, 0);
		FOR(i, n) {
			int p;
			cin >> p;
			prio[p]++;
			printq.push({ p,i });
		}
		int prio_idx = 9;
		int num = 0;

		for (; prio_idx > 0; prio_idx--) {
			if (prio[prio_idx] == 0) continue;
			while (prio[prio_idx] > 0) {

				pii f = printq.front();
				printq.pop();
				if (f.first == prio_idx) {
					num++;
					if (f.second == m) {
						cout << num << "\n";
						break;
					}
					prio[prio_idx]--;
				}
				else {
					printq.push(f);
				}
				

			}
		}
	}

	return 0;
}