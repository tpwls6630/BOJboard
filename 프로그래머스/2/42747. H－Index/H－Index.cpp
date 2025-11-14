#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> c) {
    int answer = 0;
    sort(c.begin(), c.end(), greater<int>());
    while(answer < c.size() && answer + 1 <= c[answer]) answer++;
    return answer;
}