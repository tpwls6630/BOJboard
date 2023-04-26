#include <iostream>
#include <vector>
#include <cstring>

#define ll long long
#define pii pair<int,int>
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//

int n;
int dp[1'000'001][2];
vector<vector<int>> adj;

int SNS(int curNode, bool curNodeIsEarlyAdapter, int preNode) {

	int& ret = dp[curNode][curNodeIsEarlyAdapter];
	if (ret != -1) return ret;

	ret = 0;
	if (curNodeIsEarlyAdapter) {
		
		ret++;

		for (auto nextNode : adj[curNode]) {
			if (nextNode == preNode) continue;
			ret += min(SNS(nextNode, true, curNode), SNS(nextNode, false, curNode));
		}
		
	}
	else {
		for (auto nextNode : adj[curNode]) {
			if (nextNode == preNode) continue;
			ret += SNS(nextNode, true, curNode);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	memset(dp, -1, sizeof(int) * 1'000'001 * 2);
	adj = vector<vector<int>>(n + 1, vector<int>());

	FOR(i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	adj[0].push_back(1);
	
	dp[0][1] = SNS(0, 1, 0) - 1;

	cout << dp[0][1];
	return 0;
}