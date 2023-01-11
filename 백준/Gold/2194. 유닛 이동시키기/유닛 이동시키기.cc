#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);
#define endl "\n"

using namespace std;

struct Point
{
    int y, x;
};

int n, m, a, b, k;

vector<Point> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

bool IsBounded(Point now, int dir)
{
    if (now.x < 1 || now.x + b - 1 > m || now.y < 1 || now.y + a - 1 > n)
        return false;

    return true;
}

bool CanGo(vector<vector<int>>& board, Point now, int dir)
{
    if (!IsBounded(now, dir))
        return false;
    
    for (int i = now.y; i < now.y + a; i++)
    {
        for (int j = now.x; j < now.x + b; j++)
        {
            if (board[i][j] == 1)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    FASTIO;

    
    cin >> n >> m >> a >> b >> k;
    vector<vector<int>> board(n + 1, vector<int>(m+1, 0));

    for (int i = 0; i < k; i++)
    {
        int y, x;
        cin >> y >> x;

        board[y][x] = 1;
    }
    Point start;
    cin >> start.y >> start.x;
    Point end;
    cin >> end.y >> end.x;


    vector<vector<bool>> discoverd(n+1, vector<bool>(m+1, false));
    queue<Point> q;
    q.push(start);
    discoverd[start.y][start.x] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        for (int s = 0; s < sz; s++)
        {
            Point now = q.front();
            q.pop();

            if (now.x == end.x && now.y == end.y)
            {
                cout << cnt;
                return 0;
            }

            for (int dir = UP; dir <= RIGHT; dir++)
            {
                Point next = {now.y + d[dir].y, now.x + d[dir].x};
                if (!CanGo(board, next, dir))
                    continue;

                if (discoverd[next.y][next.x])
                    continue;
                
                q.push(next);
                discoverd[next.y][next.x] = true;
            }
        }
        cnt++;
    }
    
    cout << -1;

    return 0;
}