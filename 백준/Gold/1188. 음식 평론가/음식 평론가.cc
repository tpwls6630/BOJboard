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
//#include <set>

#define pii pair<int,int>
#define ll long long
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)



using namespace std;
//########################################################################//

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	

	int sausage, reviewer;
	cin >> sausage >> reviewer;
	sausage %= reviewer;

	int numberOfGroup = gcd(sausage, reviewer);
	int ans = numberOfGroup * (reviewer / numberOfGroup - 1);

	cout << ans;
	return 0;
}
