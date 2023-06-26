#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define ll long long
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; ++VAR)
#define FOR1(VAR, TIMES) for(int VAR = 1; VAR <= TIMES; ++VAR)
using namespace std;
//########################################################################//

int n;
vector<bool> isInside, isVisited;
vector<vector<int>> adj;

ll partialBfs(int startNode) {
	ll ret = 0;
	ll numInside = isInside[startNode];
	vector<int> nextBfs;
	queue<int> bfs;
	isVisited[startNode] = true;
	bfs.push(startNode);
	while (!bfs.empty()) {
		int curNode = bfs.front(); bfs.pop();
		for (auto nextNode : adj[curNode]) {
			if (!isVisited[nextNode]) {
				isVisited[nextNode] = true;
				if (isInside[nextNode]) {
					nextBfs.push_back(nextNode);
					numInside++;
				}
				else {
					bfs.push(nextNode);
				}
			}
		}
	}
	ret = (numInside * (numInside - 1));
	for (auto nextInsideNode : nextBfs) {
		ret += partialBfs(nextInsideNode);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	isInside = vector<bool>(n, false);
	isVisited = vector<bool>(n, false);
	adj = vector<vector<int>>(n, vector<int>());
	string temp;
	cin >> temp;
	FOR(i, n) {
		isInside[i] = (temp[i] - '0' ? 1 : 0);
	}
	FOR(i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	cout << partialBfs(0);

	return 0;
}