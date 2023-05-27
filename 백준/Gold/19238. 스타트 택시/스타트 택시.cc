#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

#define COMPLETE INT_MAX
#define DISABLE INT_MAX - 1
struct Start
{
    int n, y, x, d;
};

struct End
{
    int y, x;
};

struct Point
{
    int y, x;
};

bool Cmp(Start& s1, Start& s2)
{
    if (s1.d == s2.d)
    {
        if (s1.y == s2.y)
            return s1.x < s2.x;
        return s1.y < s2.y;
    }
    return s1.d < s2.d;
}

int n, m, f;
vector<Start> s;
vector<End> e;
vector<vector<int>> board;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void UpdateDistance(int sy, int sx)
{
    vector<vector<int>> tmp = board;
    vector<vector<bool>> discovered = vector<vector<bool>>(n+1, vector<bool>(n+1, false));
    for (Start i : s)
    {
        if (i.d == COMPLETE)
            continue;
        tmp[i.y][i.x] = i.n;
    }
    discovered[sy][sx] = true;
    queue<Point> q;
    q.push({sy, sx});
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            Point now = q.front();
            q.pop();
            if (tmp[now.y][now.x] != -1 && tmp[now.y][now.x] != -2)
                s[tmp[now.y][now.x]].d = cnt;
            
            for (int i = 0; i < 4; i++)
            {
                Point next = {now.y + dy[i], now.x + dx[i]};
                if (next.y <= 0 || next.y > n || next.x <= 0 || next.x > n)
                    continue;
                if (discovered[next.y][next.x] == true)
                    continue;
                if (board[next.y][next.x] == -2)
                    continue;
                
                q.push(next);
                discovered[next.y][next.x] = true;
            }
        }
        cnt++;
    }
}

int GetEndpointDistance(int sy, int sx, int ey, int ex)
{
    vector<vector<bool>> discovered = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
    discovered[sy][sx] = true;
    queue<Point> q;
    q.push({sy, sx});
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            Point now = q.front();
            q.pop();
            if (now.y == ey && now.x == ex)
                return cnt;

            for (int i = 0; i < 4; i++)
            {
                Point next = {now.y + dy[i], now.x + dx[i]};
                if (next.y <= 0 || next.y > n || next.x <= 0 || next.x > n)
                    continue;
                if (discovered[next.y][next.x] == true)
                    continue;
                if (board[next.y][next.x] == -2)
                    continue;

                q.push(next);
                discovered[next.y][next.x] = true;
            }
        }
        cnt++;
    }

    return DISABLE;
}

void move(int sy, int sx)
{
    while (true)
    {
        UpdateDistance(sy, sx);
        vector<Start> sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end(), Cmp);

        Start &now = sorted_s[0];
        if (now.d == COMPLETE)
            return;

        if (now.d > f)
        {
            f = -1;
            return;
        }

        f -= now.d;

        int endpointDis = GetEndpointDistance(now.y, now.x, e[now.n].y, e[now.n].x);

        if (endpointDis > f)
        {
            f = -1;
            return;
        }

        f -= endpointDis;

        f += 2 * endpointDis;
        s[now.n].d = COMPLETE;
        sy = e[now.n].y;
        sx = e[now.n].x;
    } 
}

int main()
{
    FASTIO;

    cin >> n >> m >> f;

    s = vector<Start>(m);
    e = vector<End>(m);
    board = vector<vector<int>>(n+1, vector<int>(n+1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int t;
            cin >> t;
            if (t == 0)
                board[i][j] = -1;
            else
                board[i][j] = -2;
        }
    int ty, tx;
    cin >> ty >> tx;

    for(int i = 0; i < m; i++)
    {
        int sy, sx, ey, ex;
        cin >> sy >> sx >> ey >> ex;

        s[i] = {i, sy, sx, DISABLE};
        e[i] = {ey, ex};
    }

    move(ty, tx);

    cout << f;

    return 0;
}