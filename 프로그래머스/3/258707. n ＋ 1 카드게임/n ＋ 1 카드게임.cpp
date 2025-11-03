#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0;
    int n = cards.size();
    vector<int> cost(n, 10000);
    unordered_map<int, bool> jjak;
    int attackPoints = 0;
    
    for (int i = 0; i < n / 3;++i) {
        if (!jjak.empty() && jjak.find(cards[i]) != jjak.end()) {
            ++attackPoints;
            jjak.erase(cards[i]);
        }
        else {
            jjak.insert({n + 1 - cards[i], true});
        }
    }
    
    for (int i = n / 3; i < n; ++i) {
        if (!jjak.empty() && jjak.find(cards[i]) != jjak.end()) {
            if (jjak[cards[i]] == true) {
                cost[i] = 1;
            }
            else {
                cost[i] = 2;
            }
            jjak.erase(cards[i]);
        }
        else {
            jjak.insert({n + 1 - cards[i], false});
        }
    }
    
    priority_queue<int> canBuy;
    for (int i = n / 3; i <= n; i += 2) {
        ++answer;
        
        if (i == n) break;
        
        if (cost[i] == 1 || cost[i] == 2) {
            canBuy.push(-cost[i]);
            // cout << "I can buy " << i + 1 << "th card. Cost : " << cost[i] << endl;
        }
        if (cost[i + 1] == 1 || cost[i + 1] == 2) {
            canBuy.push(-cost[i + 1]);
            // cout << "I can buy " << i + 2 << "th card. Cost : " << cost[i + 1] << endl;
        }
        
        if (attackPoints > 0) {
            --attackPoints;
            // cout << "I already have jjak.\n";
            continue;
        }
        else {
            if (!canBuy.empty() && canBuy.top() + coin >= 0) {
                coin += canBuy.top();
                // cout << "I purchased " << -canBuy.top() << " coins.\n";
                canBuy.pop();
            }
            else {
                break;
            }
        }
    }
    return answer;
}