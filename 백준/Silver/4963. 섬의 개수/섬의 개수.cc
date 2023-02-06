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
int h, w;
vector<Point> d = {{1, 1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<vector<int>> board;
vector<vector<bool>> visited;

void dfs(Point now)
{
    visited[now.y][now.x] = true;

    for (int i = 0; i < 8; i++)
    {
        Point next = {now.y + d[i].y, now.x + d[i].x};
        if (next.x < 0 || next.x >= w || next.y < 0 || next.y >= h)
            continue;
        if (board[next.y][next.x] == 0)
            continue;
        if (visited[next.y][next.x] == true)
            continue;
        
        dfs(next);

    }
}

int main()
{
    FASTIO;

    while (true)
    {
        cin >> w >> h;
        if (h == 0 && w == 0)
            break;
        board.assign(h, vector<int>(w, 0));
        visited.assign(h, vector<bool>(w, false));
        int cnt = 0;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> board[i][j];
            }
        }


        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (board[i][j] == 0)
                    continue;
                if (visited[i][j] == true)
                    continue;

                dfs({i, j});
                cnt++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}