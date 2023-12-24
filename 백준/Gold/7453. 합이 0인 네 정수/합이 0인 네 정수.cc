#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <string>
#include <cstring>
#include <map>
#include <queue>

#define all(x) x.begin(), x.end()
#define FOR(X,N) for(int X = 0; X < N; ++X)
#define FOR1(X,N) for(int X = 1; X <= N; ++X)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
//############################################################################


int main()
{
     ios::sync_with_stdio(false);
     cout.tie();
     cin.tie();

     int n;
     cin >> n;

     vector<int> a(n), b(n), c(n), d(n);

     FOR(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];

     vector<int> ab, cd;
     ab.reserve(n * n);
     cd.reserve(n * n);

     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             ab.push_back(a[i] + b[j]);
             cd.push_back(c[i] + d[j]);
         }
     }

     sort(all(ab));
     sort(all(cd));

     int l = 0, r = cd.size() - 1;
     ull ans = 0;

     for (; l < ab.size(); l++) {
         int same = 1;
         while (l + 1 < ab.size() && ab[l + 1] == ab[l]) {
             ++same;
             ++l;
         }
         if (r < 0) break;
         while (r >= 0 && ab[l] + cd[r] > 0) --r;
         while (r >= 0 && ab[l] + cd[r] == 0) {
             ans += same;
             --r;
         }
     } 

     cout << ans;
    return 0;
}