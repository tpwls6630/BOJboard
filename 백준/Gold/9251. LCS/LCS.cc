#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <string>
#include <map>
#include <queue>

#define all(x) x.begin(), x.end()
#define FOR(X,N) for(int X = 0; X < N; ++X)
#define FOR1(X,N) for(int X = 1; X <= N; ++X)
#define ll long long
#define pii pair<int,int>
using namespace std;
//############################################################################



int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();

	string A, B;

	cin >> A >> B;

	vector<vector<int>> lcs(A.size() + 1, vector<int>(B.size() + 1, 0));

	for (int i = 1; i <= A.size(); i++) {
		for (int j = 1; j <= B.size(); j++) {
			int a = i - 1, b = j - 1;
			if (A[a] == B[b]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}

	cout << lcs[A.size()][B.size()];

	return 0;
}