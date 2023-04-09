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
const unsigned int M = 1234567891;
int n;

unsigned int p31[6];

long long p(int x) {
	long long ret = 1;
	long long pro = 31;
	while (x) {
		if (x & 1) {
			ret = (ret * pro) % M;
		}
		x >>= 1;
		pro = (pro * pro) % M;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	long long hash = 0;
	string temp;
	cin >> temp;
	for (int i = 0; i < n; ++i) {
		hash += (long long)(temp[i] - 'a' + 1) * p(i);
		hash = hash % M;
	}



	cout << hash;

	return 0;
}