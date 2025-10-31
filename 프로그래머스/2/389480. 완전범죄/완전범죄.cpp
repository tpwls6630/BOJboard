#include <string>
#include <vector>

using namespace std;

void setTrue(vector<vector<bool>> &dp, int a, int b, int n, int m) {
    if (a < n && b < m) dp[a][b] = true;
}

int solution(vector<vector<int>> info, int n, int m) {
    vector<vector<vector<bool>>> dp(info.size(), vector<vector<bool>>(n, vector<bool>(m, false)));

    setTrue(dp[0], info[0][0], 0, n, m);
    setTrue(dp[0], 0, info[0][1], n, m);
    
    for (int i = 1; i < info.size(); ++i) {
        
        int infoA = info[i][0];
        int infoB = info[i][1];
        
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < m; ++b) {
                if (dp[i - 1][a][b])
                {
                    setTrue(dp[i], a + infoA, b, n, m);
                    setTrue(dp[i], a, b + infoB, n, m);
                }
            }
        }
    }
    
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < m; ++b) {
            if (dp[info.size() - 1][a][b]) return a;
        }
    }

    return -1;
}