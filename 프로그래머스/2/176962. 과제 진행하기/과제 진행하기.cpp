#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;

int parseTime(string time) {
    int minutes = 0;
    istringstream ss(time);
    string buffer;
    while (getline(ss, buffer, ':')) {
        minutes *= 60;
        int i = stoi(buffer);
        minutes += i;
    }
    
    return minutes;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    sort(plans.begin(), plans.end(), [](const vector<string> &a, const vector<string> &b) {
       return a[1] < b[1]; 
    });
    
    stack<pair<string, int>> tasks;
    
    int curTime = 0;
    int i = 0;
    while(i < plans.size() || !tasks.empty())
    {
        if (i < plans.size()) {
            int start = parseTime(plans[i][1]);
            int duration = stoi(plans[i][2]);
            
            while(!tasks.empty()) {
                auto [taskName, leftTime] = tasks.top();
                tasks.pop();
                if (curTime + leftTime <= start) {
                    answer.push_back(taskName);
                    curTime += leftTime;
                }
                else {
                    tasks.push({taskName, leftTime - (start - curTime)});
                    curTime = start;
                }
                if (curTime == start) break;
            }
            curTime = start;
            tasks.push({plans[i][0], duration});
            ++i;
        }
        else {
            while(!tasks.empty()) {
                auto [taskName, leftTime] = tasks.top();
                tasks.pop();
                answer.push_back(taskName);
                
            }
        }
    }
    return answer;
}