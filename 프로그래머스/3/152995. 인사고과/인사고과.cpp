#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct P {
    int att;
    int eval;
    bool isValid;
    bool isWanho;
    
    P (int _att, int _eval, bool _isValid, bool _isWanho) : att(_att), eval(_eval), isValid(_isValid), isWanho(_isWanho) {}
};

int solution(vector<vector<int>> scores) {
    vector<P> ss;
    for(const auto &score : scores) {
        ss.emplace_back(score[0], score[1], true, false);
    }
    ss[0].isWanho = true;
    sort(ss.begin(), ss.end(), [](const P &a, const P &b) {
        if (a.att == b.att) return a.eval > b.eval;
        return a.att < b.att;
    });
    
    stack<int> st;
    for (int i = 0; i < ss.size(); ++i) {
        while(!st.empty()) {
            if (ss[st.top()].eval < ss[i].eval) {
                if (ss[st.top()].isWanho) return -1;
                ss[st.top()].isValid = false;
                st.pop();
            }
            else break;
        }
        st.push(i);
    }
    
    sort(ss.begin(), ss.end(), [](const P &a, const P &b) {
        if (!a.isValid) return false;
        if (!b.isValid) return true;
        return a.att + a.eval > b.att + b.eval;
    });
    
    int wanho = 0;
    for (;wanho < ss.size(); wanho++){
        if (ss[wanho].isWanho) break;
    }
    for (;wanho > 0; wanho--) {
        if (ss[wanho].att + ss[wanho].eval != ss[wanho - 1].att + ss[wanho - 1].eval) break;
    }
    
    return wanho + 1;
}