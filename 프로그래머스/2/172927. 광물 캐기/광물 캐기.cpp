#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> picks, vector<string> minerals)
{
    int answer = 0;
    vector<int> iminerals(minerals.size());
    for (int i = 0; i < minerals.size(); ++i)
    {
        if (minerals[i].compare("diamond") == 0)
            iminerals[i] = 0;
        else if (minerals[i].compare("iron") == 0)
            iminerals[i] = 1;
        else
            iminerals[i] = 2;
    }

    int pickSum = picks[0] + picks[1] + picks[2];
    vector<int> pickChoice(min(((int)minerals.size() + 4) / 5, pickSum), 3);
    int i = 0;
    while (picks[0]-- > 0 && i < pickChoice.size())
        pickChoice[i++] = 0;
    while (picks[1]-- > 0 && i < pickChoice.size())
        pickChoice[i++] = 1;
    while (picks[2]-- > 0 && i < pickChoice.size())
        pickChoice[i++] = 2;

    answer = 10000000;
    do
    {
        int sum = 0;
        for (i = 0; i < iminerals.size() && i / 5 < pickChoice.size(); ++i)
        {
            int pickIdx = i / 5;
            int piro = 0;
            switch (pickChoice[pickIdx])
            {
            case 0: // 다이아 곡괭이
                piro = 1;
                break;
            case 1: // 철 곡괭이
                if (iminerals[i] == 0)
                    piro = 5;
                else
                    piro = 1;
                break;
            case 2: // 돌 곡괭이
                if (iminerals[i] == 0)
                    piro = 25;
                else if (iminerals[i] == 1)
                    piro = 5;
                else
                    piro = 1;
                break;
            }
            sum += piro;
        }

        if (sum < answer)
            answer = sum;
    } while (next_permutation(pickChoice.begin(), pickChoice.end()));
    return answer;
}
