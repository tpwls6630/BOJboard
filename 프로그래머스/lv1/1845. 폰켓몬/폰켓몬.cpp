#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    vector<bool> poket(200001,0);
    int n = nums.size() / 2;
    int answer = 0;
    for(auto e : nums){
        if(!poket[e]) {
            ++answer;
            poket[e] = true;
        }
    }
    
    
    return min(n,answer);
}