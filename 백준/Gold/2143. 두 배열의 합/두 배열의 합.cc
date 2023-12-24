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

     int T;
     cin >> T;

     int n;
     cin >> n;
     vector<int> pA;
     {
         vector<int> A(n), aA(n + 1, 0);
         FOR(i, n) {
             cin >> A[i];
             aA[i + 1] = aA[i] + A[i];
             for (int j = i; j >= 0; j--) {
                 pA.push_back(aA[i + 1] - aA[j]);
             }
         }
     }

     int m;
     cin >> m;
     vector<int> pB;
     {
         vector<int> B(m), aB(m + 1, 0);
         FOR(i, m) {
             cin >> B[i];
             aB[i + 1] = aB[i] + B[i];
             for (int j = i; j >= 0; j--) {
                 pB.push_back(aB[i + 1] - aB[j]);
             }
         }
     }
     
     sort(all(pA));
     sort(all(pB));


     int l = 0, r = pB.size() - 1;
     ull ans = 0;
     for (; l < pA.size(); ++l) {
         int same = 1;
         while (l + 1 < pA.size() && pA[l + 1] == pA[l]) {
             ++same;
             ++l;
         }

         if (r < 0) break;
         while (r >= 0 && pA[l] + pB[r] > T) --r;
         while (r >= 0 && pA[l] + pB[r] == T) {
             ans += same;
             --r;
         }
     }

     cout << ans;

    return 0;
}