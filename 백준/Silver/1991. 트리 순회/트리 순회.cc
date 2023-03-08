#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
//#include <sstream>
//#include <deque>
//#include <tuple>
#include <stack>
//#include <unordered_map>
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

int n;
vector<array<int, 2>> tree(26);

void preorder(int start) {
	if (start == -19) return;
	cout << (char)('A' + start);
	preorder(tree[start][0]);
	preorder(tree[start][1]);
}
void inorder(int start) {
	if (start == -19) return;
	inorder(tree[start][0]);
	cout << (char)('A' + start);
	inorder(tree[start][1]);
}
void postorder(int start) {
	if (start == -19) return;
	postorder(tree[start][0]);
	postorder(tree[start][1]);
	cout << (char)('A' + start);
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		char a,b,c;
		cin >> a>>b>>c;
		tree[a - 'A'] = { b - 'A',c - 'A' };
	}

	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	return 0;
}