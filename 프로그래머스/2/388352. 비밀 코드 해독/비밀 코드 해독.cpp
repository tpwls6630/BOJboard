#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    vector<int> number(n);
    for (int i = 0; i < n; ++i) {
        number[i] = i + 1;
    }
    
    vector<bool> choice(n - 5, false);
    choice.insert(choice.end(), 5, true);
    
    do {
        set<int> candi;
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            if (choice[i]) candi.insert(number[i]);
        }
        
        bool isAnswer = true;
        for (int q_idx = 0; q_idx < q.size(); ++q_idx) {
            int match = 0;
            for (int i = 0; i < 5; ++i) {
                if (candi.find(q[q_idx][i]) != candi.end()) match++;
            }
            if (match != ans[q_idx]){
                isAnswer = false;
                break;
            }
        }
        
        if (isAnswer) ++answer;
    } while(next_permutation(choice.begin(), choice.end()));
    
    return answer;
}