#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // ios::sync_with_stdio(false);
  //  cin.tie();
  //  cout.tie();
  int n, k;
  cin >> n >> k;

  vector<int> cells(2 * n);
  for (int i = 0; i < 2 * n; ++i)
  {
    cin >> cells[i];
  }

  int zeros = 0;
  int stage = 0;
  vector<bool> isRobot(n, false);
  do
  {
    ++stage;
    // 1
    int tmp = cells[2 * n - 1];
    for (int i = 2 * n - 2; i >= 0; --i)
    {
      cells[i + 1] = cells[i];
    }
    cells[0] = tmp;
    for (int i = n - 2; i >= 0; --i)
    {
      isRobot[i + 1] = isRobot[i];
    }
    isRobot[0] = false;
    isRobot[n - 1] = false;
    // 2
    for (int i = n - 2; i >= 0; --i)
    {
      if (isRobot[i] && !isRobot[i + 1])
      {
        if (cells[i + 1] > 0)
        {
          --cells[i + 1];
          if (cells[i + 1] == 0)
            ++zeros;
          isRobot[i + 1] = true;
          isRobot[i] = false;
        }
      }
    }
    isRobot[n - 1] = false;
    // 3
    if (cells[0] > 0)
    {
      --cells[0];
      isRobot[0] = true;
      if (cells[0] == 0)
        ++zeros;
    }

  } while (zeros < k);

  cout << stage;
  return 0;
}