#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    int currentServer = 0;
    queue<pair<int, int>> serverTimeline; // <만료 시각, 반납 서버 개수>
    
    int n = players.size();
    for (int i = 0; i < n; ++i) {
        
        if (!serverTimeline.empty()) {
            if (serverTimeline.front().first == i) {
                currentServer -= serverTimeline.front().second;
                serverTimeline.pop();
            }
        }
        
        if (currentServer < players[i] / m) {
            int serverNeed = (players[i] / m) - currentServer;
            serverTimeline.push({i + k, serverNeed});
            currentServer += serverNeed;
            answer += serverNeed;
        }
    }
    
    return answer;
}