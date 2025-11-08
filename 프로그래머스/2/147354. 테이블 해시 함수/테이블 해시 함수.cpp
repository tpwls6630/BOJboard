#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = -1;
    col--; row_begin--; row_end--;
    sort(data.begin(), data.end(), [&](const vector<int> &a, const vector<int> &b) {
        if (a[col] == b[col]) return a[0] > b[0];
        return a[col] < b[col];
    });
    
    bool initialized = false;
    for (int i = row_begin; i <= row_end; i++) {
        int sum = 0;
        for (auto &n : data[i]) {
            sum += n % (i + 1);
        }

        if (!initialized) {answer = sum; initialized = true;}
        else {
            answer = answer ^ sum;
        }
    }
    return answer;
}