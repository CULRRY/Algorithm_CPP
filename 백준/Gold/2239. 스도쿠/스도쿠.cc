#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;
struct Point
{
    int y, x;
};
vector<vector<int>> board(10, vector<int>(10));
vector<Point> points;


int cnt = 0;

void sudoku(Point p, int n)
{

    for (int i = 1; i <= 9; i++)
    {
        if (i == p.x)
            continue;
        if (board[p.y][i] == board[p.y][p.x])
            return;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (i == p.y)
            continue;
        if (board[i][p.x] == board[p.y][p.x])
            return;
    }

    int startY = ((p.y - 1) / 3) * 3 + 1;
    int startX = ((p.x - 1) / 3) * 3 + 1;
    for (int i = startY; i < startY + 3; i++)
    {
        for (int j = startX; j < startX + 3; j++)
        {
            if (i == p.y && j == p.x)
                continue;
            if (board[i][j] == board[p.y][p.x])
                return;
        }
    }

    if (n == cnt)
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cout << board[i][j];
            }
            cout << "\n";
        }
        
        exit(0);
    }

    for (int i = 1; i <= 9; i++)
    {
        Point next = points[n];

        board[next.y][next.x] = i;
        sudoku(next, n + 1);
        board[next.y][next.x] = 0;
    }
}

int main()
{
    FASTIO;

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            char c;
            cin >> c;
            if (c == '0')
            {
                cnt++;
                points.push_back({i, j});
            }
            board[i][j] = static_cast<int>(c - '0');
        }
    }

    for (int i = 1; i <= 9; i++)
    {
        Point now = points[0];
        board[now.y][now.x] = i;
        sudoku(now, 1);
        board[now.y][now.x] = 0;
    }
    cout << "";
    return 0;
}