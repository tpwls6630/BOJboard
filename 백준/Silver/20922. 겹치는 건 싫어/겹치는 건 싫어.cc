#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int l = 0, r = 0;
    vector<int> freq(100001, 0);

    int max_length = 0;
    while (r < n)
    {
        if (freq[arr[r]] < k)
        {
            max_length = max(max_length, r - l + 1);
            freq[arr[r]]++;
            r++;
        }
        else
        {
            while (l < r && freq[arr[r]] >= k)
            {
                freq[arr[l]]--;
                l++;
            }
        }
    }

    cout << max_length;
    return 0;
}