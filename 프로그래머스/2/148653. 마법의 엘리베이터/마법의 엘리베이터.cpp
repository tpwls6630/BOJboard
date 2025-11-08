#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey > 0) {
        int left = storey % 10;
        if (left <= 4) answer += left;
        else if (left == 5) {
            if (storey / 10 % 10 <= 4) answer += left;
            else {
                storey += 5;
                answer += 5;
            }
        }
        else {
            storey += 10 - left;
            answer += 10 - left;
        }
        storey /= 10;
    }
    return answer;
}