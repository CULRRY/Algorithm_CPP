#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define red first
#define blue second

using namespace std;
struct Point
{
    int y, x;
};

Point Red;
Point Blue;
Point Hole;

enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
vector<Point> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int cnt = INT_MAX;
bool f = false;

int tilt(vector<vector<char>> board)
{
    queue<pair<Point, Point>> q;
    q.push({Red, Blue});
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        cnt++;
        if (cnt > 10)
            break;
        for (int s = 0; s < sz; s++)
        {
            Point nowRed = q.front().red;
            Point nowBlue = q.front().blue;
            q.pop();
            for (int i = UP; i <= RIGHT; i++)
            {
                Point nextRed = nowRed;
                Point nextBlue = nowBlue;
                while (board[nextRed.y][nextRed.x] == '.' || board[nextBlue.y][nextBlue.x] == '.')
                {
                    if (board[nextRed.y][nextRed.x] == '.')
                        nextRed = {nextRed.y + d[i].y, nextRed.x + d[i].x};

                    if (board[nextBlue.y][nextBlue.x] == '.')
                        nextBlue = {nextBlue.y + d[i].y, nextBlue.x + d[i].x};
                }

                if (nextRed.y == nextBlue.y && nextRed.x == nextBlue.x)
                {
                    if (board[nextRed.y][nextRed.x] == 'O')
                        continue;

                    if (i == UP)
                    {
                        if (nowBlue.y > nowRed.y)
                        {
                            nextBlue.y -= d[i].y;
                        }
                        else
                        {
                            nextRed.y -= d[i].y;
                        }
                    }
                    else if (i == DOWN)
                    {
                        if (nowBlue.y > nowRed.y)
                        {
                            nextRed.y -= d[i].y;
                        }
                        else
                        {
                            nextBlue.y -= d[i].y;
                        }
                    }
                    else if (i == LEFT)
                    {
                        if (nowBlue.x > nowRed.x)
                        {
                            nextBlue.x -= d[i].x;
                        }
                        else
                        {
                            nextRed.x -= d[i].x;
                        }
                    }
                    else
                    {
                        if (nowBlue.x > nowRed.x)
                        {
                            nextRed.x -= d[i].x;
                        }
                        else
                        {
                            nextBlue.x -= d[i].x;
                        }
                    }
                }

                if (board[nextBlue.y][nextBlue.x] == 'O')
                    continue;

                if (board[nextRed.y][nextRed.x] == 'O')
                    return cnt;
                
                if (nextRed.y == nowRed.y && nextRed.x == nowRed.x && nextBlue.y == nowBlue.y && nextBlue.x == nowBlue.x )
                    continue;

                nextRed = {nextRed.y - d[i].y, nextRed.x - d[i].x};
                nextBlue = {nextBlue.y - d[i].y, nextBlue.x - d[i].x};
                q.push({nextRed, nextBlue});
            }
        }
    }
    return -1;
}

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                board[i][j] = '.';
                Red = {i, j};
            }
            else if (board[i][j] == 'B')
            {
                board[i][j] = '.';
                Blue = {i, j};
            }
            else if (board[i][j] == 'O')
            {
                Hole = {i, j};
            }
        }
    }

    cout << tilt(board);

    return 0;
}