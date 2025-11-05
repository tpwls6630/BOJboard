#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int left = 0, right = 0;
    int sum = 0;
    vector<int> ans(3, 100000000);
    for (;right < sequence.size(); ++right) {
        sum += sequence[right];
        while(sum > k && left < right) {
            sum -= sequence[left++];
        }
        if (sum == k) {
            if (right - left + 1 < ans[0]) {
                ans[0] = right - left + 1;
                ans[1] = left;
                ans[2] = right;
            }
        }
    }
    return {ans[1], ans[2]};
}