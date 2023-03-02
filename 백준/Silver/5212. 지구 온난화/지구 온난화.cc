#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int main()
{
    FASTIO;

    int r, c;
    cin >> r >> c;

    vector<vector<char>> board(r, vector<char>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<vector<char>> ans(r, vector<char>(c, '.'));
    int miny = r, maxy = 0, minx = c, maxx = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == '.')
                continue;
            else
            {
                int cnt = 0;
                for (int k = 0; k < 4; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                    {
                        cnt++;
                        continue;
                    }
                    if (board[ny][nx] == '.')
                        cnt++;
                }
                if (cnt <= 2)
                {
                    ans[i][j] = 'X';

                    miny = std::min(miny, i);
                    minx = std::min(minx, j);
                    maxy = std::max(maxy, i);
                    maxx = std::max(maxx, j);
                }
            }
        }
    }

    
    for (int i = miny; i <= maxy; i++)
    {
        for (int j = minx; j <= maxx; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}