#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define pii pair<int,int>
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//

int n, s;
const int MAXNODE = 50;
const vector<int> edges(MAXNODE, 0);

const bool CANMAKE = true;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;

	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(s + 1, edges));

	if (n >= 3) {
		dp[3][1][0] = CANMAKE;
		dp[3][1][1] = 2;
		dp[3][1][2] = 1;
	}

	for (int node = 3; node < n; node++) {
		for (int S = 1; S <= s; S++) {

			if (dp[node][S][0] == CANMAKE) {
				for (int numOfEdge = 1; numOfEdge <= node - 1; numOfEdge++) {
					
					if (dp[node][S][numOfEdge]) {
						if (S + numOfEdge > s) continue;

						vector<int>& nextNode = dp[node + 1][S + numOfEdge];
						if (nextNode[0] == !CANMAKE) {
							nextNode = dp[node][S];
							nextNode[numOfEdge]--;
							nextNode[numOfEdge + 1]++;
							nextNode[1]++;
						}
					
					}
				}
			}
		}
	}

	cout << dp[n][s][0];

	return 0;
}