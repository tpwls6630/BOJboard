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

vector<int> primes(int n) {
    vector<bool> p(n+1, true);
    vector<int> ret(1, 0);

    for (int i = 2; i <= (int)sqrt(n); i++) {
        if (p[i] == false) continue;
        for (int j = i * 2; j <= n; j += i) {
            p[j] = false;
        }
    }

    for (int i = 2; i <= n; i++)
        if (p[i]) ret.push_back(i);

    return ret;
}

int main()
{
     ios::sync_with_stdio(false);
     cout.tie();
     cin.tie();

     int n;
     cin >> n;

     vector<int> arr = primes(n);

     int l = 1, r = 1, sum = 0;
     int ans = 0;
     for (; l < arr.size(); l++) {
         if (r == arr.size()) break;
         sum -= arr[l - 1];
         while (r < arr.size() && sum + arr[r] <= n) sum += arr[r++];
         if (sum == n) ans++;
     }

     cout << ans;

    return 0;
}