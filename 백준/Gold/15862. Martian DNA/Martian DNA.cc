#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K, R;
    cin >> N >> K >> R;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    vector<int> neo(K, 0);

    for (int i = 0; i < R; ++i)
    {
        int x, y;
        cin >> x >> y;
        neo[x] = y;
    }

    int len = 200'001;

    int l = 0, r = 0;
    int satisfied = 0;
    vector<int> cnt(K, 0);
    while (r < N)
    {
        if (neo[arr[r]] == 0)
        {
            r++;
            continue;
        }
        cnt[arr[r]]++;
        if (cnt[arr[r]] == neo[arr[r]])
        {
            satisfied++;
        }
        while (satisfied == R)
        {
            len = min(len, r - l + 1);

            if (neo[arr[l]] > 0)
            {
                cnt[arr[l]]--;
                if (cnt[arr[l]] < neo[arr[l]])
                {
                    satisfied--;
                }
            }
            l++;
        }
        r++;
    }

    if (len == 200'001)
        cout << "impossible";
    else
        cout << len;

    return 0;
}