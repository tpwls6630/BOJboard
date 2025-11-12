#include <string>
#include <vector>

using namespace std;
const int MAX = (1 << 31) - 1;
bool check(vector<int> &a, vector<int> &t) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != t[i]) return false;
    }
    return true;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = MAX;
    vector<int> begin(beginning.size()), end(target.size());
    int n = beginning.size();
    int m = beginning[0].size();
    for (int i = 0; i < n; i++) {
        int x = 0;
        int y = 0;
        for (auto &b : beginning[i]) {
            x <<= 1;
            x += b;
        }
        for (auto &t : target[i]) {
            y <<= 1;
            y += t;
        }
        begin[i] = x;
        end[i] = y;
    }
    
    int rmask = (1 << m) - 1;
    for (int rcase = 0; rcase < (1 << n); rcase++) {
        vector<int> b(begin);
        for (int r = 0; r < n; r++) {
            if (rcase & (1 << r)) {
                b[r] = ~b[r] & rmask; 
            }
        }
        
        for (int ccase = 0; ccase < (1 << m); ccase++) {
            vector<int> bb(b);
            for (int r = 0; r < n; r++) {
                bb[r] = bb[r] ^ ccase;
            }
            
            if (check(bb, end)) {
                int rf = 0, cf = 0;
                for (int r = 0; r < n; r++) {
                    if (rcase & (1 << r)) rf++;
                }
                for (int c = 0; c < m; c++) {
                    if (ccase & (1 << c)) cf++;
                }

                answer = min(answer, rf + cf);
            }
        }
        
        
    }
    if (answer == MAX) return -1;
    return answer;
}