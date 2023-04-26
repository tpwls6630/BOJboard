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

int n;
vector<pii> startToEnd;
int startDate, endDate;
int days[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };

inline int dateToInt(pii date) {
	return days[date.first - 1] + date.second;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	startDate = dateToInt(pii{ 3,1 });
	endDate = dateToInt(pii{ 12,1 });

	cin >> n;
	startToEnd.resize(n);

	FOR(i, n) {
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		startToEnd[i] = { dateToInt({sm,sd}), dateToInt({em,ed}) };
	}

	sort(all(startToEnd));
	
	if (startToEnd[0].first > startDate) { cout << 0; return 0; }

	int curEndDate = startDate, curPivot = 0, nextFlower = 0;
	int ans = 0;
	bool changed = true;
	while (curEndDate < endDate) {
		
		for (; curPivot < n && startToEnd[curPivot].first <= curEndDate; curPivot++) {
			if (startToEnd[nextFlower].second < startToEnd[curPivot].second) {
				nextFlower = curPivot;
				changed = true;
			}
		}
		if (!changed) {
			cout << 0;
			return 0;
		}
		ans++;
		curEndDate = startToEnd[nextFlower].second;
		changed = false;
	}

	cout << ans;
	return 0;
}