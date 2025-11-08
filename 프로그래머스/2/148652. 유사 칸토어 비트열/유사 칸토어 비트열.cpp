#include <string>
#include <vector>

using namespace std;

vector<int> cantor(int n, long long l, long long r) {
    if (n == 0) return {0, 1, 1, 1};
    vector<int> ret(4);
    vector<int> prev = cantor(n - 1, l / 5, r / 5);
    ret[0] = 5 * prev[0] + prev[1];
    ret[1] = 4 * prev[1];
    
    int left = prev[2];
    if (left == 1) {
        switch(l % 5) {
            case 4:
                ret[1]--;
            case 3:
                ret[0]--;
                ret[1]--;
            case 1:
                ret[1]--;
            case 0:
                ret[2] = 1;
                break;
            case 2:
                ret[1] -= 2;
                ret[2] = 0;
                break;
        }
    }
    else {
        ret[2] = 0;
        ret[0] -= l % 5;
    }
    
    int right = prev[3];
    if (right == 1) {
        switch(r % 5) {
            case 0:
                ret[1]--;
            case 1:
                ret[0]--;
                ret[1]--;
            case 3:
                ret[1]--;
            case 4:
                ret[3] = 1;
                break;
            case 2:
                ret[1] -= 2;
                ret[3] = 0;
                break;
        }
    }
    else {
        ret[3] = 0;
        ret[0] -= 4 - r % 5;
    }
    
    return ret;
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    vector<int> result = cantor(n,l - 1,r - 1);
    return result[1];
}