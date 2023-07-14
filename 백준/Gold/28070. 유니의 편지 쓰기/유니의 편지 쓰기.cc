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

int n;
int datetoi(string str) {
	int ret = 0;
	FOR(i, 7) {
		if (i == 4)continue;
		ret += str[i] - '0';
		ret *= 10;
	}
	return ret / 10;
}
bool mycomp(pair<int, int>& p1, pair<int, int>& p2) {
	if (p1.first == p2.first) {
		return p1.second > p2.second;
	}
	return p1.first < p2.first;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(); cout.tie();

	cin >> n;
	vector<pair<int, int>> dates;
	FOR(i, n) {
		string start, end;
		cin >> start >> end;
		dates.push_back({ datetoi(start), 1 });
		dates.push_back({ datetoi(end), -1 });
	}
	sort(all(dates), mycomp);


	int sum = 0;
	int M = 0;
	int ret = 0;
	for (auto d : dates) {
		sum += d.second;
		if (sum > M) {
			ret = d.first;
			M = sum;
		}
	}
	int year = ret / 100, month = ret % 100;
	cout << year << "-";
	cout.width(2);
	cout.fill('0');
	cout << month;
	
	return 0;
}