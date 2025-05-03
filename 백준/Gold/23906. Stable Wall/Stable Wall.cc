#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include "stdlib.h"
using namespace std;
#define FOR(_i, _x) for (int _i = 0; _i < _x; _i++)

bool IsStableBoard(const vector<vector<bool>> &board)
{
    int r = board.size();
    int c = board[0].size();
    for (int x = 0; x < c; ++x)
    {
        for (int y = 0; y < r; ++y)
        {
            if (board[y][x] == true)
            {
                while (++y < r)
                {
                    if (board[y][x] == false)
                        return false;
                }
            }
        }
    }
    return true;
}

bool IsDone(const vector<vector<bool>> &board)
{
    int r = board.size();
    int c = board[0].size();
    for (int x = 0; x < c; ++x)
    {
        for (int y = 0; y < r; ++y)
        {
            if (board[y][x] == false)
                return false;
        }
    }
    return true;
}

vector<char> solution()
{
    static const array<int, 2> dir[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int r, c;
    cin >> r >> c;
    vector<vector<char>> initialBoard(r, vector<char>(c));
    vector<char> ans;
    FOR(i, r)
    {
        FOR(j, c)
        {
            cin >> initialBoard[i][j];
        }
    }
    vector<vector<bool>> board(r, vector<bool>(c, false));

    for (int y = r - 1; y >= 0; --y)
    {
        for (int x = 0; x < c; ++x)
        {
            if (board[y][x] == false)
            {
                // try 블록 쌓기
                char block = initialBoard[y][x];
                vector<vector<bool>> tempBoard(board);

                // bfs
                queue<array<int, 2>> q;
                q.push({y, x});
                tempBoard[y][x] = true;
                while (!q.empty())
                {
                    auto [cy, cx] = q.front();
                    q.pop();
                    for (auto [dy, dx] : dir)
                    {
                        int ny = cy + dy;
                        int nx = cx + dx;
                        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                            continue;
                        if (tempBoard[ny][nx] == false && initialBoard[ny][nx] == block)
                        {
                            q.push({ny, nx});
                            tempBoard[ny][nx] = true;
                        }
                    }
                }

                if (IsStableBoard(tempBoard))
                {
                    board = tempBoard;
                    ans.push_back(block);
                    x = -1;
                }
            }
        }

        // 이 줄이 다 채워졌는지 확인
        for (int x = 0; x < c; ++x)
        {
            // 실패함
            if (board[y][x] == false)
            {
                return vector<char>();
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    FOR(i, t)
    {
        cout << "Case #" << i + 1 << ": ";
        auto ans = solution();
        if (ans.empty())
            cout << "-1\n";
        else
        {
            for (char c : ans)
            {
                cout << c;
            }
            cout << '\n';
        }
    }

    return 0;
}