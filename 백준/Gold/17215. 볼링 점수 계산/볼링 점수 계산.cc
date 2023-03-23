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

    string sq;
    cin >> sq;

    vector<array<int,2>> frame(12, { 0,0 });
    int now = 0;
    int shoot = 0;
    for (auto c : sq) {
        if (shoot == 2) {
            shoot = 0;
            now++;
        }
        if (c == '-') {
            shoot++;
        }
        else if (c == 'P') {
            frame[now][shoot++] = 10 - frame[now][0];
        }
        else if (c == 'S') {
            frame[now][shoot] = 10;
            shoot = 2;
        }
        else {
            frame[now][shoot++] = (c - '0');
        }
    }
    int ans = 0;
    now = 0;
    shoot = 0;
    for (auto c : sq) {
        if (shoot == 2) {
            shoot = 0;
            now++;
        }
        if (now == 10) break;
        if (c == '-') {
            shoot++;
        }
        else if (c == 'P') {
            ans += frame[now][shoot++] + frame[now + 1][0];
        }
        else if (c == 'S') {
            ans += frame[now][shoot];

            if (frame[now + 1][0] == 10) {
                ans += 10 + frame[now + 2][0];
            }
            else {
                ans += frame[now + 1][0] + frame[now + 1][1];
            }
            
            shoot = 2;
        }
        else {
            ans += frame[now][shoot++];
        }
    }
    cout << ans;
    return 0;
}