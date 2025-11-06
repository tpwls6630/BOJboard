#include <string>
#include <vector>
#include <cmath>
using namespace std;



long long solution(vector<int> sequence) {
    long long answer = 0;
    
    // vector<vector<long long>> accsum(sequence.size());
    long long sum = 0;
    long long maxsum = 1L << 63, minsum = 1L << 63 - 1;
    for (int i = 0; i < sequence.size(); ++i) {
        sum += sequence[i] * (i % 2 == 0 ? 1 : -1);
        // accsum[i] = sum;
        maxsum = max(maxsum, sum);
        minsum = min(minsum, sum);
    }
    maxsum = max(maxsum, 0LL);
    minsum = min(minsum, 0LL);
    return abs(maxsum - minsum);
}