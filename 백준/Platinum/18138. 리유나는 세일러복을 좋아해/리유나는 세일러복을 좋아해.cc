#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; ++VAR)
#define FOR1(VAR, TIMES) for(int VAR = 1; VAR <= TIMES; ++VAR)
using namespace std;
//########################################################################//

int n, m;
vector<bool> done;
vector<int> shirtIdxAttachWith;
vector<vector<int>> canAttach;
bool dfs(int shirtIdx) {
	if (shirtIdx == -1) return false;
	for (int i = 0; i < canAttach[shirtIdx].size(); ++i) {
		int collarIdx = canAttach[shirtIdx][i];

		if (done[collarIdx]) continue;
		done[collarIdx] = true;

		if (shirtIdxAttachWith[collarIdx] == -1 || dfs(shirtIdxAttachWith[collarIdx])) {
			shirtIdxAttachWith[collarIdx] = shirtIdx;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	vector<int> widthShirt(n), widthCollar(m);
	done = vector<bool>(m, false);
	shirtIdxAttachWith = vector<int>(m, -1);
	canAttach = vector<vector<int>>(n, vector<int>());
	FOR(i, n) cin >> widthShirt[i];
	FOR(i, m) cin >> widthCollar[i];

	FOR(i, n) {
		int T = widthShirt[i];
		FOR(j, m) {
			int C = 4 * widthCollar[j];
			if ((2 * T <= C && C <= 3 * T) || (4 * T <= C && C <= 5 * T)) {
				canAttach[i].push_back(j);
			}
		}
	}

	int ans = 0;
	FOR(i, n) {
		done = vector<bool>(m, false);
		if (dfs(i)) ++ans;
	}
	cout << ans;

	return 0;
}