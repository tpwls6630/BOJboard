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

int n, m;
vector<char> stand = { '.','O','-','|','/','\\','^','<','v','>' };
vector<char> lay = { '.','O','|','-','\\','/','<','v','>','^' };

int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();

	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	FOR(i, n) {
		FOR(j, m) {
			char temp;
			cin >> temp;
			FOR(idx, 10) {
				if (temp == stand[idx]) {
					board[i][j] = lay[idx];
					break;
				}
			}
		}
	}

	for(int j = m - 1; j>=0; j--) {
		FOR(i, n) {
			cout << board[i][j];
		}
		cout << "\n";
	}
	return 0;
}