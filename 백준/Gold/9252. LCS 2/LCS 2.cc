#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#define all(x) x.begin(), x.end()
#define FOR(X, N) for (int X = 0; X < N; ++X)
#define FOR1(X, N) for (int X = 1; X <= N; ++X)
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
using namespace std;
// ############################################################################

int main()
{
    ios::sync_with_stdio(false);
    cout.tie();
    cin.tie();

    string str1, str2;
    cin >> str1 >> str2;

    vector<vector<int>> lcs(str1.length() + 1, vector<int>(str2.length() + 1, 0));
    vector<vector<char>> lcsBacktrack(str1.length() + 1, vector<char>(str2.length() + 1, 0));

    for (int i = 1; i <= str1.length(); ++i)
    {
        for (int j = 1; j <= str2.length(); ++j)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                lcsBacktrack[i][j] = 'd';
            }
            else if (lcs[i - 1][j] > lcs[i][j - 1])
            {
                lcs[i][j] = lcs[i - 1][j];
                lcsBacktrack[i][j] = 'u';
            }
            else
            {
                lcs[i][j] = lcs[i][j - 1];
                lcsBacktrack[i][j] = 'l';
            }
        }
    }

    cout << lcs[str1.length()][str2.length()] << endl;
    int x = str1.length(), y = str2.length();
    stack<char> st;
    while (x != 0 && y != 0)
    {
        if (lcsBacktrack[x][y] == 'd')
        {
            st.push(str1[x - 1]);
            --x;
            --y;
        }
        else if (lcsBacktrack[x][y] == 'u')
            --x;
        else if (lcsBacktrack[x][y] == 'l')
            --y;
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}