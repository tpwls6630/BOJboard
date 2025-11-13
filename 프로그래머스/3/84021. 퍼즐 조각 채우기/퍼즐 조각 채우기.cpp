#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Puzzle {
  public:
    vector<vector<bool>> shape;
    int size;
    
    Puzzle(vector<vector<int>> &board) {
        int u = board.size() - 1, d = 0;
        int l = board[0].size() - 1, r = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j]){
                    u = min(u, i);
                    d = max(d, i);
                    l = min(l, j);
                    r = max(r, j);
                }
            }
        }
        
        shape = vector<vector<bool>>(d-u+1, vector<bool>(r-l+1, false));
        size = 0;
        for (int i = u; i <= d; i++) {
            for (int j = l; j <= r; j++) {
                if (board[i][j]) {
                    shape[i-u][j-l] = true;
                    size++;
                }
            }
        }
    }
    
    Puzzle(const Puzzle &p) {
        shape = vector<vector<bool>>(p.shape);
        size = p.size;
    }   
    
    void rotateCW() {
        
        int r = shape.size();
        int c = shape[0].size();
        
        vector<vector<bool>> newShape(c, vector<bool>(r, false));
        
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r; i++) {
                newShape[j][i] = shape[r - 1 - i][j];
            }
        }
        
        shape = move(newShape);
    }
    
    bool isEqual(const Puzzle &a, const Puzzle &b) const {

        if (a.shape.empty() || a.shape[0].empty()) return false;
        if (b.shape.empty() || b.shape[0].empty()) return false;
        if (a.shape.size() != b.shape.size() || a.shape[0].size() != b.shape[0].size()) return false;
        
        for (int i = 0; i < a.shape.size(); i++) {
            for (int j = 0; j < a.shape[0].size(); j++) {
                if (a.shape[i][j] != b.shape[i][j]) return false;
            }
        }
        return true;
    }
    
    bool operator==(const Puzzle &p) const {
        
        if (this->size != p.size) return false;
        
        Puzzle temp(p);
        int rot = 3;
        do {

            if (isEqual(*this, temp)) return true;
            temp.rotateCW();
            
        } while(rot-->0);
        
        return false;
    }
};

Puzzle getPuzzle(const vector<vector<int>> &board, int x, int y, set<pair<int, int>> &visited, int target) {
    
    const int dir[4][2] = {{-1, 0}, {0 ,1}, {1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    q.push({x, y});
    visited.insert({x, y});
    
    vector<vector<int>> mask(board.size(), vector<int>(board[0].size(), 0));
    
    while(!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        mask[cur.first][cur.second] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dir[i][0];
            int ny = cur.second + dir[i][1];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size()) continue;
            if (visited.find({nx, ny}) == visited.end() && board[nx][ny] == target) {
                q.push({nx, ny});
                visited.insert({nx, ny});
            }
        }
    }
    
    return Puzzle(mask);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    vector<Puzzle> female, male;
    set<pair<int, int>> visited_board, visited_table;
    int n = table.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (game_board[i][j] == 0 && visited_board.find({i, j}) == visited_board.end()) {
                Puzzle f = getPuzzle(game_board, i, j, visited_board, 0);
                female.push_back(f);
            }
            if (table[i][j] == 1&& visited_table.find({i, j}) == visited_table.end()) {
                Puzzle m = getPuzzle(table, i, j, visited_table, 1);
                male.push_back(m);
            }
        }
    }
    
    vector<bool> a_matched(female.size(), false);
    for (const Puzzle &m : male) {
        for (int i = 0; i < female.size(); i++) {
            if (a_matched[i]) continue;
            if (female[i] == m) {
                answer += m.size;
                a_matched[i] = true;
                break;
            }
        }
    }
    return answer;
}