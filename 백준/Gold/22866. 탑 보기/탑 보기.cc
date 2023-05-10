#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <array>

#define all(x) x.begin(), x.end()
#define FOR(X,N) for(int X = 0; X < N; ++X)
#define FOR1(X,N) for(int X = 1; X <= N; ++X)
#define ll long long
#define pii pair<int,int>
using namespace std;
//############################################################################

typedef int HEIGHT, BUILDINGIDX, IDX;
const int LEFT = 0, RIGHT = 1, INF = 1'000'000;
int n;
vector<HEIGHT> height;

int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();

	cin >> n;
	height = vector<HEIGHT>(n + 1, 0);
	vector<array<BUILDINGIDX, 2>> nearestHigherBuildingIndex(n + 1, {-INF, INF});
	vector<array<BUILDINGIDX, 2>> numCanSee(n + 1, { 0, 0 });

	FOR1(i, n) cin >> height[i];

	
	
	//calc can see leftside
	//left to right
	stack<pair<HEIGHT, IDX>> monoDecrease;

	FOR1(i, n) {

		pair<HEIGHT, IDX> curStack = { height[i], i };

		if (monoDecrease.empty()) 
			monoDecrease.push(curStack);
		else {

			while (!monoDecrease.empty() && monoDecrease.top().first < height[i]) {
				auto [H, I] = monoDecrease.top(); monoDecrease.pop();
				if (H != height[i]) 
					nearestHigherBuildingIndex[I][RIGHT] = i;
			}
			monoDecrease.push(curStack);
		}
	}
	
	//calc can see rightside
	//right to left
	monoDecrease = stack<pair<HEIGHT, IDX>>();

	FOR(md, n) {
		int i = n - md;
		pair<HEIGHT, IDX> curStack = { height[i], i };

		if (monoDecrease.empty()) 
			monoDecrease.push(curStack);
		else {

			while (!monoDecrease.empty() && monoDecrease.top().first < height[i]) {
				auto [H, I] = monoDecrease.top(); monoDecrease.pop();
				if (H != height[i])
					nearestHigherBuildingIndex[I][LEFT] = i;
			}
			monoDecrease.push(curStack);
		}
	}
	

	FOR1(i, n) {
		int left = nearestHigherBuildingIndex[i][LEFT];
		if (left != -INF) 
			numCanSee[i][LEFT] += numCanSee[left][LEFT] + 1;
	}
	FOR(md, n) {
		int i = n - md;
		int right = nearestHigherBuildingIndex[i][RIGHT];
		if (right != INF)
			numCanSee[i][RIGHT] += numCanSee[right][RIGHT] + 1;
	}
	
	FOR1(i, n) {
		auto [l, r] = nearestHigherBuildingIndex[i];
		int sum = numCanSee[i][LEFT] + numCanSee[i][RIGHT];
		cout << sum << ' ';
		if (sum > 0) {
			if (r == INF)
				cout << l;
			else if (l == -INF)
				cout << r;
			else {
				if (i - l > r - i)
					cout << r;
				else
					cout << l;
			}
		}
		cout << "\n";
	}

	return 0;
}