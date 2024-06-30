#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>

#define all(x) x.begin(), x.end()
#define FOR(X, N) for (int X = 0; X < N; ++X)
#define FOR1(X, N) for (int X = 1; X <= N; ++X)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
using namespace std;
// ############################################################################

vector<bool> isprime;

ll solve(ll n)
{

  ll sq = sqrt(n);

  isprime = vector<bool>(sq + 1, true);
  for (ll i = 2; i <= sq; ++i)
  {
    if (!isprime[i])
      continue;
    for (ll j = i * i; j <= sq; j += i)
    {
      isprime[j] = false;
    }
  }

  ll ret = 1;
  for (ll i = 2; i <= sq; ++i)
  {
    if (!isprime[i])
      continue;
    int power = 0;
    while (n % i == 0)
    {
      ++power;
      n /= i;
    }
    if (power == 0)
      continue;
    ret *= (ll)(pow(i, power)) - (ll)(pow(i, power - 1));
  }
  if (n != 1)
    ret *= n - 1;

  return ret;
}

int main()
{
  ios::sync_with_stdio(false);
  cout.tie();
  cin.tie();

  ll n;
  cin >> n;
  cout << solve(n);

  return 0;
}