#include <string>
#include <vector>

using namespace std;
const int MAX = 1 << 31 - 1;
int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> dp(y + 1, MAX);
    dp[x] = 0;
    for (int i = x; i <= y; ++i) {
        if (dp[i] == MAX) continue;
        if (i + n <= y) dp[i + n] = min(dp[i + n], dp[i] + 1);
        if (2 * i <= y) dp[2 * i] = min(dp[2 * i], dp[i] + 1);
        if (3 * i <= y) dp[3 * i] = min(dp[3 * i], dp[i] + 1);
    }
    if (dp[y] == MAX) return -1;
    return dp[y];
    
}