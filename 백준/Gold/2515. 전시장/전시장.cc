#include <algorithm>
#include <iostream>
#include <vector>
//#include <queue>
#include <cmath>
//#include <cstring>
#include <string>
//#include <sstream>
#include <stack>
//#include <typeinfo>
#include <array>
//#include <bitset>
//#include <format>
#include <numeric>

#define pii pair<int,int>
#define IM 2'147'483'647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//

int n,S;
vector<pair<int,int>> picture;
vector<long long> dp;

long long museum(int x) {
	if (x == 0) return 0;

	long long& ret = dp[x];
	if (ret != -1) return ret;

	int s = 1, e = x - 1;
	int mid, idx = 0;
	while (s <= e) {
		mid = (s + e) / 2;
		if (picture[mid].first <= picture[x].first - S) {
			s = mid + 1;
			idx = max(idx, mid);

		}
		else {
			e = mid - 1;
		}
	}

	return ret = max(museum(idx) + picture[x].second, museum(x - 1));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> S;
	picture.resize(n + 1);
	dp = vector<long long>(n + 1, -1);

	FOR(i, n) {
		cin >> picture[i + 1].first >> picture[i + 1].second;
	}
	sort(all(picture));

	/*
	//같은 높이를 가진 작품 중 가격이 최대인 것 만 선별
	pair<int, int> curp = { 0,0 };
	vector<pair<int, int>> temp; // temp[0]는 쓰레기값
	for (int i = 1; i <= n; i++) {
		if (curp.first == picture[i].first) {
			if (curp.second < picture[i].second) {
				curp.second = picture[i].second;
			}
		}
		else {
			temp.push_back(curp);
			curp = picture[i];
		}
	}
	temp.push_back(curp);
	swap(temp, picture);
	vector<pair<int, int>>().swap(temp);
	*/

	cout << museum(n);
	return 0;
}