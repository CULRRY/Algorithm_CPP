#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

void Switch(char& c)
{
    if (c == '#') c = 'O';
    else c = '#';
}

void TurnOn(vector<string>& board, int y, int x)
{
    Switch(board[y][x]);
    if (y > 0) Switch(board[y-1][x]);
    if (y < 9) Switch(board[y+1][x]);
    if (x > 0) Switch(board[y][x-1]);
    if (x < 9) Switch(board[y][x+1]);
}


int main()
{
    FASTIO;

    vector<string> board(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> board[i];
    }
    int ans = 1000;
    for (int c = 0; c < (1 << 10); c++)
    {
        int cnt = 0;
        bool canSolve = true;
        vector<string> tmp(board);

        for (int i = 0; i < 10; i++)
        {
            int bit = c & (1 << i);
            if (bit == (1 << i))
            {
                TurnOn(tmp, 0, i);
                cnt++;
            }
        }

        for (int i = 1; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (tmp[i-1][j] == 'O')
                {
                    TurnOn(tmp, i, j);
                    cnt++;
                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            if (tmp[9][i] == 'O')
            {
                canSolve = false;
                break;
            }
        }

        if (canSolve)
            ans = std::min(ans, cnt);
    }

    if (ans > 100)
        cout << -1;
    else
        cout << ans;
     

    return 0;
}