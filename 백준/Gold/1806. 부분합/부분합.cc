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

const int UNDEFINED = 1000000;
int main()
{
    ios::sync_with_stdio(false);
    cout.tie();
    cin.tie();

    int n, s;
    cin >> n >> s;

    vector<int> arr(1, 0);
    FOR(i, n) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int l = 1, r = 1, sum = 0;
    int ans = UNDEFINED;
    for (; l <= n; l++) {

        sum -= arr[l - 1];
        while (r <= n && sum < s) {
            sum += arr[r++];
        }
        //sum은 l부터 r까지의 합
        //현재 r은 1 큰 상태

        if (sum >= s) {
            ans = min(ans, r - l);
        }
    }

    if (ans == UNDEFINED) ans = 0;
    cout << ans;
    return 0;
}