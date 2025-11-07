#include <string>
#include <vector>
#include <stack>

using namespace std;
typedef pair<int, int> pii;
vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    
    stack<pii> st;
    for (int i = 0; i < numbers.size(); ++i) {
        while(!st.empty()) {
            pii f = st.top();
            if (f.first < numbers[i]) {
                answer[f.second] = numbers[i];
                st.pop();
            }
            else break;
        }
        st.push({numbers[i], i});
    }
    
    while(!st.empty()) {
        pii f = st.top();
        answer[f.second] = -1;
        st.pop();
    }
    return answer;
}