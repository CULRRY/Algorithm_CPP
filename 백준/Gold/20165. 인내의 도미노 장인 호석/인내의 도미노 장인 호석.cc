#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);
#define endl "\n"

using namespace std;
int n, m, r;
struct Point
{
    int y, x;
};
int cnt = 0;
void move(vector<vector<int>>& board, int y, int x, char dir)
{
    int remain = board[y][x] - 1;
    if (board[y][x] != 0)
    {
        cnt++;
        board[y][x] = 0;
    }
    Point d;
    if (dir == 'E')
    {
        d = {0, 1};
    }
    else if (dir == 'W')
    {
        d = {0, -1};
    }
    else if (dir == 'N')
    {
        d = {-1, 0};
    }
    else
    {
        d = {1, 0};
    }
    Point now = {y, x};
    while (remain > 0)
    {
        now = {now.y + d.y, now.x + d.x};
        if (now.y <= 0 || now.y > n || now.x <= 0 || now.x > m)
            break;
        if (board[now.y][now.x] > remain)
        {
            remain = board[now.y][now.x];
        }
        remain--;
        if (board[now.y][now.x] != 0)
        {
            board[now.y][now.x] = 0;
            cnt++;
        }
    }
    


}


int main()
{
    FASTIO;


    cin >> n >> m >> r;

    vector<vector<int>> board(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<vector<int>> tmp(board);

    for (int i = 0; i < r; i++)
    {
        int y, x;
        char d;
        cin >> y >> x >> d;
        move(tmp, y, x, d);
        cin >> y >> x;
        tmp[y][x] = board[y][x];
    }

    cout << cnt << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (tmp[i][j] != 0)
                cout << 'S' << " ";
            else
                cout << 'F' << " ";
        }
        cout << endl;
    }

    return 0;
}