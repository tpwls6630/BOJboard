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
#define LLONG_MAX 9223372036854775807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; ++VAR)
using namespace std;
//#######################################################

int n, k;

vector<int> ICPC(vector<int> arr, int standard) {
    if (arr.size() == 0) return vector<int>();
    vector<int> ret(1);
    vector<int> bigger, lesser;
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > arr[0]) bigger.push_back(arr[i]);
        else if (arr[i] < arr[0]) lesser.push_back(arr[i]);
    }
    ret[0] = lesser.size() + 1 + standard;
    vector<int> b = ICPC(bigger, lesser.size() + 1 + standard), l = ICPC(lesser, standard);
    ret.insert(ret.end(), all(b));
    ret.insert(ret.end(), all(l));
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    vector<vector<int>> icpcs(n,vector<int>(k)), acms(n);

    FOR(i, n) {
        FOR(j, k) {
            cin >> icpcs[i][j];
        }
        acms[i] = ICPC(icpcs[i], 0);
    }

    int cnt = 0;
    vector<bool> visited(n,false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            cnt++;
            for (int j = i + 1; j < n; j++) {
                if (!visited[j]) {
                    bool common = true;
                    for (int p = 0; p < k; p++) {
                        if (acms[i][p] != acms[j][p]) {
                            common = false; break;
                        }
                    }
                    if (common) {
                        visited[j] = true;
                    }
                }
            }
        }
    }

    cout << cnt;
    return 0;
}