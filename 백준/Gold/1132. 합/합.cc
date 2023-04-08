#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
//#include <string>
//#include <tuple>
//#include <stack>
#include <array>
//#include <format>
#define INT_MAX 2147483647
#define LLONG_MAX 9'223'372'036'854'775'807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; ++VAR)
using namespace std;
//#######################################################



 


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> abc(n);
    vector<bool> visited(10, false);

    FOR(i, n)
        cin >> abc[i];

    vector<pair<long long, int>> ABC(10,{0,0});
    for (auto e : abc) {
        for (int i = 0; i < e.size(); i++) {
            if (i == 0) ABC[e[i] - 'A'].second = 1;
            visited[e[i] - 'A'] = true;
            ABC[e[i] - 'A'].first += pow(10, e.size() - i - 1);
        }
    }
    int cnt = 0;
    for (auto e : visited)
        if (e) cnt++;
    sort(all(ABC),greater());

    if (cnt == 10) {
        int nonzero = -1, zero = -1;
        for (int i = 9; i >= 0; i--) {
            if (nonzero == -1 && ABC[i].second == 1) nonzero = i;
            if (zero == -1 && ABC[i].second == 0) zero = i;
        }
        if (nonzero == 9) {
            long long temp = ABC[zero].first;
            ABC.erase(ABC.begin() + zero);
            ABC.push_back({ temp,0 });
        }
    }



    int num = 9;
    long long ans = 0;
    for (auto e : ABC) {
        ans += e.first * num--;
    }
    cout << ans;
    return 0;
}