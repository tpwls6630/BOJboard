#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

float getWinRate(const vector<vector<int>> &diceA, const vector<vector<int>> &diceB)
{
    int n = diceA.size();

    vector<int> scoreA(pow(6, n)), scoreB(pow(6, n));
    for (int i = 0; i < pow(6, n); ++i)
    {
        int ii = i;
        for (int d = 0; d < n; ++d)
        {
            int face = ii % 6;
            scoreA[i] += diceA[d][face];
            scoreB[i] += diceB[d][face];
            ii /= 6;
        }
    }

    int aWinCnt = 0;
    for (const int &sA : scoreA)
    {
        for (const int &sB : scoreB)
        {
            if (sA > sB)
                ++aWinCnt;
        }
    }

    return aWinCnt / pow(6.0, n);
}

vector<int> solution(vector<vector<int>> dice)
{
    vector<int> answer;

    int n = dice.size() / 2;
    vector<bool> choice(n, false);
    choice.insert(choice.end(), n, true);

    float maxWinRate = 0;
    vector<bool> optimalChoice;
    vector<vector<int>> diceA(n), diceB(n);
    do
    {
        int aidx = 0, bidx = 0;
        for (int i = 0; i < 2 * n; ++i)
        {
            if (choice[i])
                diceA[aidx++] = dice[i];
            else
                diceB[bidx++] = dice[i];
        }
        float winRate = getWinRate(diceA, diceB);
        if (winRate > maxWinRate)
        {
            maxWinRate = winRate;
            optimalChoice = vector<bool>(choice);
        }
    } while (next_permutation(choice.begin(), choice.end()));

    for (int i = 0; i < 2*n; ++i) {
        if (optimalChoice[i]) answer.push_back(i + 1);
    }
    return answer;
}
