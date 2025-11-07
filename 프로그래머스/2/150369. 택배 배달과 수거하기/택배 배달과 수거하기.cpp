#include <string>
#include <vector>
#include <queue>
#include <array>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    priority_queue<array<int, 2>> delivery, pickup;
    for (int i = 0; i < n; i++)  {
        if (deliveries[i] == 0) continue;
        delivery.push({i + 1, deliveries[i]});
    }
    for (int i = 0; i < n; i++) {
        if (pickups[i] == 0) continue;
        pickup.push({i + 1, pickups[i]});
    }
    
    while(!delivery.empty() || !pickup.empty()) {
        long long distance = 0;
        if (!delivery.empty()) {
            distance = max(distance, (long long)delivery.top()[0]);
        }
        if (!pickup.empty()) {
            distance = max(distance, (long long)pickup.top()[0]);
        }
        int dcap = cap;
        while (dcap > 0 && !delivery.empty()) {
            if (dcap >= delivery.top()[1]) {
                dcap -= delivery.top()[1];
                delivery.pop();
            }
            else {
                auto temp = delivery.top();
                delivery.pop();
                temp[1] -= dcap;
                delivery.push(temp);
                dcap = 0;
            }
        }
        dcap = cap;
        while (dcap > 0 && !pickup.empty()) {
            if (dcap >= pickup.top()[1]) {
                dcap -= pickup.top()[1];
                pickup.pop();
            }
            else {
                auto temp = pickup.top();
                pickup.pop();
                temp[1] -= dcap;
                pickup.push(temp);
                dcap = 0;
            }
        }
        answer += 2LL * distance;
    }
    return answer;
}