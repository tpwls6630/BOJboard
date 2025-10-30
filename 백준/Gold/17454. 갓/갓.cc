#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <unordered_map>
#include <string>
using namespace std;

bool solution(vector<int> &ratio)
{
    int dh, ds, hd, hs, sd, sh;
    dh = ratio[0];
    ds = ratio[1];
    hd = ratio[2];
    hs = ratio[3];
    sd = ratio[4];
    sh = ratio[5];

    if ((sd - sh) >= 0 || (hd - hs) >= 0)
        return true;
    if (hd * sd > (hd - hs) * (sd - sh))
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    while (k--)
    {
        vector<int> ratio(6);
        for (int i = 0; i < 6; i++)
        {
            cin >> ratio[i];
        }

        if (solution(ratio))
        {
            cout << "GOD\n";
        }
        else
        {
            cout << "KDH\n";
        }
    }
    return 0;
}