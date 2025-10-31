#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
int useCar(vector<vector<char>> &board, char target)
{
    int n = board.size();
    int m = board[0].size();
    
    static int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pii> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    int ret = 0;
    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dir[i][0];
            int ny = cur.second + dir[i][1];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!visited[nx][ny] && board[nx][ny] == target) {
                board[nx][ny] = 'x';
                ret++;
            }
            
            if (!visited[nx][ny] && board[nx][ny] == '.'){
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'x') board[i][j] = '.';
        }
    }
    
    return ret;
}

int useCrane(vector<vector<char>> &board, char target) {
    int n = board.size();
    int m = board[0].size();
    int ret = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if (board[i][j] == target) {
                board[i][j] = '.';
                ret++;
            }
        }
    }
    return ret;
}
int solution(vector<string> storage, vector<string> requests) {
    int n = storage.size();
    int m = storage[0].length();
    
    int answer = n * m;
    vector<vector<char>> board(n + 2, vector<char>(m + 2, '.'));
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            board[i + 1][j + 1] = storage[i][j];
        }
    }
    
    for(string &req : requests) {
        char target = req[0];
        if (req.length() == 1) answer -= useCar(board, target);
        else answer -= useCrane(board, target);
    }
    return answer;
}