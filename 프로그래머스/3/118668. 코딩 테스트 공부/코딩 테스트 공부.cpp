#include <string>
#include <vector>

using namespace std;
const int MAX = (1 << 31) - 1;
int solution(int alp, int cop, vector<vector<int>> problems) {
    problems.push_back({0,0,1,0,1});
    problems.push_back({0,0,0,1,1});
    int answer = MAX;
    int maxAl = 0, maxCo = 0;
    for (auto problem : problems) {
        maxAl = max(maxAl, problem[0]);
        maxCo = max(maxCo, problem[1]);
    }

    vector<vector<int>> dp(max(maxAl, alp) + 1, vector<int>(max(maxCo, cop) + 1, MAX));
    if (maxAl <= alp && maxCo <= cop) return 0;
    dp[alp][cop] = 0;
    for (int al = alp; al < dp.size(); al++) {
        for (int co = cop; co < dp[0].size(); co++) {
            for (auto &problem : problems) {
                if (al >= problem[0] && co >= problem[1]) {
                    int nal = al + problem[2];
                    int nco = co + problem[3];
                    if (nal >= dp.size()) nal = dp.size() - 1; // clamp
                    if (nco >= dp[0].size()) nco = dp[0].size() - 1; // clamp
                    dp[nal][nco] = min(dp[nal][nco], dp[al][co] + problem[4]);
                }
            }
        }
    }
    
    for (int al = maxAl; al < dp.size(); al++) {
        for (int co = maxCo; co < dp[0].size(); co++) {
            answer = min(answer, dp[al][co]);
        }
    }
    return answer;
}