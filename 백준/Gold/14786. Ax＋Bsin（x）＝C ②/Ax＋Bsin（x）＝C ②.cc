#include <algorithm>
#include <iostream>
#include <vector>
//#include <queue>
#include <cmath>
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

double a, b, c;
// f(x) = ax + bsin(x) - c
// y = f'(t)*(x-t) + f(t) = 0
// x = -f(t)/f'(t) + t
double df(double x) {
	return a + b * cos(x);
}
double f(double x) {
	return a * x + b * sin(x) - c;
}
double nx(double t) {
	return -f(t) / df(t) + t;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b >> c;

	double t = 0.0;
	while (abs(f(t)) > 1e-9) {
		t = nx(t);
	}
	cout << fixed;
	cout.precision(12);
	cout << t;

	return 0;
}