#include "stdio.h"
#define FOR(a,x) for(int a = 0; a < x; ++a)
int k, n, p[30] = {2003,2011,2017,2027,2029,2039,2053,2063,2069,2081,2083,2087,2089,2099,2111,2113,2129,2131,2137,2141,2143,2153,2161,2179,2203,2207,2213,2221,2237,2239};
int main() {
	scanf("%d%d", &k, &n); 
	FOR(i, k) { FOR(j, n) printf("%d ", p[i] * (j + 1)); }
	return 0;
}
