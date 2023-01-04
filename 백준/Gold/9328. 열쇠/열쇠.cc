#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;
struct Point
{
    int y, x;
};
int h, w;
const vector<Point> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isBound(Point p)
{
    if (p.y <= 0 || p.y > h)
        return false;
    if (p.x <= 0 || p.x > w)
        return false;

    return true;
}

int main()
{
    FASTIO;

    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> h >> w;
        vector<vector<char>> board(h + 1, vector<char>(w + 1));
        vector<Point> Enter;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                cin >> board[i][j];
                if (i == 1 || j == 1 || i == h || j == w)
                {
                    if (board[i][j] != '*')
                    {
                        Enter.push_back({i, j});
                    }
                }
            }
        }

        vector<bool> keys(26, false);
        vector<queue<Point>> doors(26, queue<Point>());
        string s;
        cin >> s;
        if (s != "0")
        {
            for (char c : s)
            {
                keys[c - 'a'] = true;
            }
        }

        int cnt = 0;
        vector<vector<bool>> discoverd(h + 1, vector<bool>(w + 1, false));
        queue<Point> q;
        for (int i = 0; i < Enter.size(); i++)
        {
            q.push(Enter[i]);
        }

        while (!q.empty())
        {

            Point now = q.front();
            char &nowChar = board[now.y][now.x];
            q.pop();

            if (nowChar >= 'A' && nowChar <= 'Z')
            {
                if (keys[nowChar + 32 - 'a'] == false)
                {
                    doors[nowChar - 'A'].push(now);
                    continue;
                }
                else
                    nowChar = '.';
            }
            else if (nowChar >= 'a' && nowChar <= 'z')
            {
                keys[nowChar - 'a'] = true;
                queue<Point> &doorQ = doors[nowChar - 32 - 'A'];
                while (!doorQ.empty())
                {
                    Point p = doorQ.front();
                    doorQ.pop();
                    q.push(p);
                }

                nowChar = '.';
            }
            else if (nowChar == '$')
            {
                cnt++;
                nowChar = '.';
            }

            for (int i = 0; i < 4; i++)
            {
                Point next = {now.y + d[i].y, now.x + d[i].x};

                if (!isBound(next))
                    continue;

                char nextChar = board[next.y][next.x];
                if (discoverd[next.y][next.x])
                    continue;

                if (nextChar == '*')
                    continue;

                discoverd[next.y][next.x] = true;
                q.push(next);
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}