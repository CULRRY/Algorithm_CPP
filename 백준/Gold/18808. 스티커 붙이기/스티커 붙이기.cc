#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n, m, k;
void Rotate(vector<vector<int>> &v)
{
    int r = v.size();
    int c = v[0].size();
    vector<vector<int>> tmp(c, vector<int>(r, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            tmp[j][r - i - 1] = v[i][j];
        }
    }

    v = tmp;
}

bool CanIn(vector<vector<int>> &sticker, vector<vector<int>> &board, int y, int x)
{
    if (y + sticker.size() - 1 >= n)
        return false;

    if (x + sticker[0].size() - 1 >= m)
        return false;
        
    for (int i = y; i < y + sticker.size(); i++)
    {
        for (int j = x; j < x + sticker[0].size(); j++)
        {
            if (sticker[i - y][j - x] == 1 && board[i][j] == 1)
                return false;
        }
    }

    return true;
}

void stick(vector<vector<int>> &sticker, vector<vector<int>> &board, int y, int x)
{
    for (int i = y; i < y + sticker.size(); i++)
    {
        for (int j = x; j < x + sticker[0].size(); j++)
        {
            if (sticker[i-y][j-x] == 1)
                board[i][j] = sticker[i - y][j - x];
        }
    }
}

bool Attach(vector<vector<int>> &sticker, vector<vector<int>> &board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (CanIn(sticker, board, i, j))
            {
                stick(sticker, board, i, j);
                return true;
            }
        }
    }

    return false;
}

int main()
{
    FASTIO;

    cin >> n >> m >> k;
    vector<vector<int>> board(n, vector<int>(m, 0));
    int ans = 0;
    for (int t = 0; t < k; t++)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> sticker(r, vector<int>(c, 0));
        int cnt = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> sticker[i][j];
                if (sticker[i][j] == 1)
                    cnt++;
            }
        }

        if (Attach(sticker, board))
        {
            ans += cnt;
            continue;
        }
        for (int c = 0; c < 3; c++)
        {
            Rotate(sticker);

            if (Attach(sticker, board))
            {
                ans += cnt;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}