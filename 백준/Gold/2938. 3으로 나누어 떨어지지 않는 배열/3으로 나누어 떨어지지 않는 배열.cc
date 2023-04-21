#include <algorithm>
#include <iostream>
#include <vector>
//#include <queue>
//#include <cmath>
//#include <cstring>
//#include <string>
//#include <sstream>
//#include <stack>
//#include <typeinfo>
//#include <array>
//#include <bitset>
//#include <format>

#define pii pair<int,int>
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> remain(3, vector<int>());
	vector<int> nums(n);
	FOR(i, n) {
		cin >> nums[i];
		remain[nums[i] % 3].push_back(i);
	}

	bool valid = true;
	if (remain[0].size() > remain[1].size() + remain[2].size() + 1) {
		// 0끼리는 붙으면 안되는데 0 사이에 들어갈 1과 2가 충분하지 않음
		// 0 1 0 2 0 0
		valid = false;
	}
	else if (remain[1].size() % n != 0 && remain[0].size() == 0) {
		// 1 과 2가 동시에 있으면서 1 과 2 사이에 들어갈 0이 없음
		// 1 1 1 2 2 2 
		valid = false;
	}

	if (valid == false) {
		cout << -1;
		return 0;
	}

	if (remain[0].size() == 0) {
		//1만 있거나 2만 있는 상황
		//그대로 출력해도 무관
		for (auto e : nums) {
			cout << e << ' ';
		}
		return 0;
	}
	else {
		// 0 한개는 1과 2 사이에 넣을 것으로 예약해둬야 함
		// 나머지 0은 첫번째 부터 시작해서 한칸 띄고 넣어주면 됨
		// 0과 {1, 2}를 번갈아가며 출력
		
		
		int cnt = 0;
		int zeros = 1;
		int sel = 1;
		int i = 0;
		while (cnt < n) {
			if (sel == 1 && i == remain[1].size()) {
				// 1을 전부 출력한 상황
				sel = 2;
				i = 0;
				cout << nums[remain[0][0]] << ' ';
				cnt++;
			}
			else if (zeros < remain[0].size()) {
				cout << nums[remain[0][zeros++]] << ' ';
				cnt++;
			}
			if (i < remain[sel].size()) {
				cout << nums[remain[sel][i++]] << ' ';
				cnt++;
			}
		}
	}

	return 0;
}