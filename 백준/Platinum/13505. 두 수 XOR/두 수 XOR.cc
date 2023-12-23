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

const int MAXDIGIT = 63;

class BTrie {
public:
    BTrie(){
        zero = NULL;
        one = NULL;
    }

    void insert(const ull key) {
        insert(key, MAXDIGIT);
    }

    void insert(const ull key, const int digit) {

        if (digit == -1) return;

        bool next = (key & ((ull)1 << digit));
        if (next) {
            if (!one) {
                one = new BTrie();
            }
            one->insert(key, digit - 1);
        }
        else {
            if (!zero) {
                zero = new BTrie();
            }
            zero->insert(key, digit - 1);
        }
    }

    ull xorFind(ull key) {
        return xorFind(key, MAXDIGIT);
    }

    ull xorFind(ull key, int digit) {

        if (digit == -1) return 0;

        bool next = (key & ((ull)1 << digit));
        if (next) {
            if (zero) {
                return ((ull)1 << digit) + zero->xorFind(key, digit - 1);
            }
            else {
                return one->xorFind(key, digit - 1);
            }
        }
        else {
            if (one) {
                return ((ull)1 << digit) + one->xorFind(key, digit - 1);
            }
            else {
                return zero->xorFind(key, digit - 1);
            }
        }
    }

private:
    BTrie* zero, *one;
};
int main()
{
     ios::sync_with_stdio(false);
     cout.tie();
     cin.tie();

     int n;
     cin >> n;

     BTrie trie;

     ull l;
     cin >> l;
     trie.insert(l);

     ull ans = 0;

     FOR(i, n - 1) {
         cin >> l;
         trie.insert(l);
         ans = max(ans, trie.xorFind(l));
     }

     cout << ans;
    return 0;
}