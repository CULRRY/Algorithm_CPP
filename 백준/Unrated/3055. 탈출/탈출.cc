#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
struct Point
{
    int y, x;
};

int r, c;
vector<vector<char>> board;
queue<Point> q;
queue<Point> water;
vector<Point> d = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
vector<vector<bool>> discovered;
Point goal;

void expandWater()
{
    int sz = water.size();
    while (sz--)
    {
        Point now = water.front();
        water.pop();

        for (int i = 0; i < 4; i++)
        {
            Point next = {now.y + d[i].y, now.x + d[i].x};
            if (next.y < 0 || next.y >= r || next.x < 0 || next.x >= c)
                continue;

            if (board[next.y][next.x] == '.')
            {
                board[next.y][next.x] = '*';
                water.push(next);
            }
        }
    }
}

string bfs()
{
    int cnt = 0;
    while (!q.empty())
    {
        expandWater();
        int sz = q.size();

        while (sz--)
        {
            Point now = q.front();
            q.pop();
            if (now.y == goal.y && now.x == goal.x)
            {
                return to_string(cnt);
            }

            for (int i = 0; i < 4; i++)
            {
                Point next = {now.y + d[i].y, now.x + d[i].x};
                if (next.y < 0 || next.y >= r || next.x < 0 || next.x >= c)
                    continue;

                if (board[next.y][next.x] == 'X')
                    continue;
                if (board[next.y][next.x] == '*')
                    continue;
                if (discovered[next.y][next.x] == true)
                    continue;

                discovered[next.y][next.x] = true;
                q.push(next);
            }
        }
        cnt++;
    }

    return "KAKTUS";
}

int main()
{
    FASTIO;

    cin >> r >> c;
    board = vector<vector<char>>(r, vector<char>(c));
    discovered = vector<vector<bool>>(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '*')
                water.push({i, j});
            else if (board[i][j] == 'S')
            {
                board[i][j] = '.';
                q.push({i, j});
                discovered[i][j] = true;
            }
            else if (board[i][j] == 'D')
                goal = {i, j};
        }
    }

    cout << bfs() << endl;

    return 0;
}