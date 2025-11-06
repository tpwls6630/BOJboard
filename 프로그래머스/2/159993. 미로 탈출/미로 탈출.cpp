#include <string>
#include <vector>
#include <queue>
#include <array>
#include <set>

using namespace std;
typedef pair<int, int> pii;
int bfs(const vector<string> &map, pii start, pii end) {
    const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    queue<array<int, 3>> q;
    set<pii> visited;
    visited.insert(start);
    q.push({start.first, start.second, 0});
    
    while(!q.empty()) {
        auto [x, y, t] = q.front();
        q.pop();

        if (end.first == x && end.second == y) return t;
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= map.size() || nx < 0 || ny >= map[0].length() || ny < 0) continue;
            if (map[nx][ny] == 'X') continue;
            if (visited.find({nx, ny}) == visited.end()) {
                visited.insert({nx, ny});
                q.push({nx, ny, t + 1});
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    pii start, lever, exit;
    for (int i = 0; i < maps.size(); ++i) {
        for (int j = 0 ; j < maps[i].length(); ++j) {
            if (maps[i][j] == 'S') {start = {i, j};maps[i][j] = 'O';}
            else if (maps[i][j] == 'L') {lever = {i, j}; maps[i][j] = 'O';}
            else if (maps[i][j] == 'E') {exit = {i, j}; maps[i][j] = 'O';}
        }
    }
    
    int a = bfs(maps, start, lever);
    int b = bfs(maps, lever, exit);
    if (a == -1 || b == -1) return -1;
    return a + b;
}