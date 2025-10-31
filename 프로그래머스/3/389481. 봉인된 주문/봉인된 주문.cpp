#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string intToString(long long number) {
    string ret = "";
    --number;
    while (number >= 0)
    {
        int left = number % 26;
        ret.push_back('a' + left);
        number = (number / 26) - 1;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

long long stringToInt(string str) {
    long long ret = 0;
    for (int i = str.length(); i > 0; --i)
    {
        ret += (str[i - 1] - 'a' + 1) * pow((long long)26, str.length() - i);
    }
    return ret;
}

string solution(long long n, vector<string> bans) {
    vector<long long> ll_bans(bans.size());
    for (int i = 0; i < bans.size(); ++i) {
        ll_bans[i] = stringToInt(bans[i]);
    }
    
    sort(ll_bans.begin(), ll_bans.end());
    
    for (int i = 0; i < ll_bans.size(); ++i) {
        if (n >= ll_bans[i]) ++n;
        else break;
    }
    return intToString(n);
}