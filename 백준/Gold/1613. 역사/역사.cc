//#include <algorithm>
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
	
	int n, k;
	cin >> n >> k;
	vector<vector<int>> dist(n + 1, vector<int>(n + 1,INF));

	FOR(i, k) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	int q;
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		if (dist[a][b] != INF) cout << -1 << "\n";
		else if (dist[b][a] != INF) cout << 1 << "\n";
		else cout << 0 << "\n";
	}

	return 0;
}
