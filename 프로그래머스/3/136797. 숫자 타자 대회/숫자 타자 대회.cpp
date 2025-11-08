#include <string>
#include <vector>

using namespace std;
const int COST[7][5] = 
{{8,7,6,7,8},
 {6,5,4,5,6},
 {5,3,2,3,5},
 {4,2,1,2,4},
 {5,3,2,3,5},
 {6,5,4,5,6},
 {8,7,6,7,8}};
typedef pair<int, int> pii;
const pii BASE = {3,2};
const int MAX = 1 << 31 - 1;
pii intToPii(int thumb) {
    if (thumb == 0) return {3, 1};
    return {(thumb - 1) / 3, (thumb - 1) % 3};
}

int moveCost(int start, int end) {
    pii s = intToPii(start);
    pii e = intToPii(end);
    pii move = {e.first - s.first, e.second - s.second};
    return COST[BASE.first + move.first][BASE.second + move.second];
}

int solution(string numbers) {
    int answer = MAX;
    
    vector<vector<int>> dp(numbers.length() + 1, vector<int>(100, MAX));
    dp[0][4 * 10 + 6] = 0;
    
    for (int step = 1; step <= numbers.length(); step++) {
        int target = numbers[step - 1] - '0';
        for (int left = 0; left <= 9; left++) {
            for (int right = 0; right <= 9; right++) {
                if (left == right) continue; // 손은 겹칠 수 없음
                
                int cost = dp[step - 1][10 * left + right];
                if (cost != MAX) {

                    // 이미 이 숫자 위에 손이 있는 경우
                    if(left == target || right == target) {
                        dp[step][10 * left + right] = min(dp[step][10 * left + right], cost + 1);
                        continue;
                    }
                    
                    // 왼손 움직이기
                    dp[step][10 * target + right] = min(dp[step][10 * target + right], dp[step - 1][10 * left + right] + moveCost(left, target));
                    
                    //오른손 움직이기
                    dp[step][10 * left + target] = min(dp[step][10 * left + target], dp[step - 1][10 * left + right] + moveCost(right, target));
                }
            }
        }
    }
    
    for (int left = 0; left <= 9; left++) {
        for(int right = 0; right <= 9; right++) {
            if (dp[numbers.length()][10*left + right] != MAX) {
                answer = min(answer, dp[numbers.length()][10 * left + right]);
            }
        }
    }
    return answer;
}