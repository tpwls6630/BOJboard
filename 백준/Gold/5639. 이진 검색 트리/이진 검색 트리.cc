#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
//#include <cstring>
#include <string>
//#include <sstream>
//#include <stack>
//#include <typeinfo>
#include <array>
//#include <bitset>
//#include <format>

#define llong long long
#define vi vector<int> 
#define mat vector<vi> 
#define INT_MIN -2147483647 - 1
#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;

vector<int> v;
void postorder(int start, int end) {
	if (start > end) return;
	if (start == end) {
		cout << v[start] << "\n";
		return;
	}
	int root = v[start];
	int mid = end;
	for (int i = start + 1; i <= end; i++) {
		if (v[i] > root) {
			mid = i - 1;
			break;
		}
	}
	postorder(start + 1, mid);
	postorder(mid + 1, end);
	cout << root << "\n";
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int temp;
	while (cin >> temp) {
		v.push_back(temp);
	}
	postorder(0, v.size() - 1);
	
	return 0;
}