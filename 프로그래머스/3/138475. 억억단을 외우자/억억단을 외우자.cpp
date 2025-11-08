#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer(starts.size());
    unordered_map<long long, long long> maps;
    for (int i = 1; i <= e; i++) {
        maps[i * i]++;
        for (int j = i + 1; j <= e / i; j++) {
            maps[i * j] +=2;
        }
    }
    
    vector<pair<int, int>> _starts;
    for (int i = 0; i < starts.size(); i++) {
        _starts.emplace_back(starts[i], i);
    }
    sort(_starts.begin(), _starts.end(), greater<pair<int, int>>());

    int s = e + 1;
    int maxcnt = 0;
    int maxnum = 0;
    for (auto &sip : _starts) { // start, index pair of _starts
        while (s > sip.first) {
            s--;
            if (maxcnt <= maps[s]) {
                maxcnt = maps[s];
                maxnum = s;
            }
        }
        answer[sip.second] = maxnum;
    }
    
    return answer;
}