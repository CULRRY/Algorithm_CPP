#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

vector<vector<int>> board(5, vector<int>(5, 0));

bool Check()
{
    int cnt = 0;

    bool bingoDiagleft = true;
    bool bingoDiagRight = true;
    for (int i = 0; i < 5; i++)
    {
        bool bingoVert = true;
        bool bingoHriz = true;
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] != -1)
                bingoHriz = false;

            if (board[j][i] != -1)
                bingoVert = false;
            
            if (i == j)
            {
                if (board[i][j] != -1)
                    bingoDiagleft = false;
            }

            if ((4 - i) == j)
            {
                if (board[i][j] != -1)
                    bingoDiagRight = false;
            }
        }
        if (bingoHriz)
            cnt++;
        if (bingoVert)
            cnt++;
    }

    if (bingoDiagleft)
        cnt++;
    if (bingoDiagRight)
        cnt++;

    if (cnt >= 3)
        return true;
    else
        return false;

}

void Find(int n)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == n)
                board[i][j] = -1;
        }
    }
}

int main()
{
    FASTIO;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= 25; i++)
    {
        int n;
        cin >> n;
        Find(n);

        if(Check())
        {
            cout << i;
            break;
        }
        
    }

    return 0;
}