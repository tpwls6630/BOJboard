#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <deque>
#include <tuple>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <typeinfo>

#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	if (n % 2 != 0) { cout << 0; return 0; }

	vector<long long> p(31, 0);
	p[2] = 3;
	for (int i = 4; i < n + 1; i = i + 2) {
		p[i] = 2;
		for (int j = i - 2; j >= 2; j = j - 2) {
			if (j == i - 2) {
				p[i] += 3 * p[j];
			}
			else {
				p[i] += 2 * p[j];
			}
			
		}
	}

	cout << p[n];
	return 0;
}