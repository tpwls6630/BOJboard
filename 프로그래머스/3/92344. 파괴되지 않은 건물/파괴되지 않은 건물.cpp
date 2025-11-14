#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> gradient(n, vector<int>(m, 0));
    
    for (auto &s : skill) {
        int type = s[0] == 1 ? -1 : 1;
        int degree = s[5];
        int r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4];
        gradient[r1][c1] += type * degree;
        if (c2 < m - 1) gradient[r1][c2 + 1] += -1 * type * degree;
        if (r2 < n - 1) {
            gradient[r2 + 1][c1] += -1 * type * degree;
            if (c2 < m - 1) gradient[r2 + 1][c2 + 1] += type * degree;
        }
    }
    
    vector<vector<int>> integral(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += gradient[i][j];
            integral[i][j] = sum;
        }
    }
    
    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += integral[i][j];
            integral[i][j] = sum;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] + integral[i][j] > 0) answer++;
        }
    }
    return answer;
}