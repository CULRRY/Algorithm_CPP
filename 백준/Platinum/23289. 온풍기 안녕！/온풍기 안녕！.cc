#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

enum {EMPTY, RIGHT, LEFT, UP, DOWN, INQURE};
enum {U = 1, R = 2};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct Point
{
    int x, y;
};

struct Fan
{
    Point p;
    int d;
};


vector<vector<int>> T;
vector<vector<int>> WU;
vector<vector<int>> WR;

vector<Fan> fans;
vector<Point> inq;

int r, c, k;

bool IsBound(Point p)
{
    if (p.x <= 0 || p.x > r || p.y <= 0 || p.y > c)
        return false;
    return true;
}

void scatterUP(int x, int y)
{
    queue<Point> q;
    x = x - 1;
    q.push({x, y});
    vector<vector<bool>> discoverd(r+1, vector<bool>(c + 1, false));
    discoverd[x][y] = true;
    int p = 5;
    while (!q.empty())
    {
        int sz = q.size();
        if (p == 0)
            return;
        while (sz--)
        {
            Point now = q.front();
            q.pop();

            T[now.x][now.y] += p;

            Point next = {now.x - 1, now.y};
            if (IsBound(next))
            {
                if (WU[now.x][now.y] != U)
                {
                    if (discoverd[next.x][next.y] == false)
                    {
                        q.push(next);
                        discoverd[next.x][next.y] = true;
                    }
                }
            }
            
            next = {now.x - 1, now.y - 1};
            if (IsBound(next))
            {
                if (WU[now.x][now.y - 1] != U && WR[now.x][now.y - 1] != R)
                {
                    if (discoverd[next.x][next.y] == false)
                    {
                        q.push(next);
                        discoverd[next.x][next.y] = true;
                    }
                }
            }

            next = {now.x - 1, now.y + 1};
            if (IsBound(next))
            {
                if (WU[now.x][now.y + 1] != U && WR[now.x][now.y] != R)
                {
                    if (discoverd[next.x][next.y] == false)
                    {
                        q.push(next);
                        discoverd[next.x][next.y] = true;
                    }
                }
            }
        }
        p--;
    }
}

void scatterDOWN(int x, int y)
{
    queue<Point> q;
    x = x + 1;
    q.push({x, y});
    vector<vector<bool>> discoverd(r + 1, vector<bool>(c + 1, false));
    discoverd[x][y] = true;
    int p = 5;
    while (!q.empty())
    {
        int sz = q.size();
        if (p == 0)
            return;
        while (sz--)
        {
            Point now = q.front();
            q.pop();

            T[now.x][now.y] += p;

            Point next = {now.x + 1, now.y};
            if (IsBound(next))
            {
                if (WU[now.x + 1][now.y] != U)
                {
                    if (discoverd[next.x][next.y] == false)
                    {
                        q.push(next);
                        discoverd[next.x][next.y] = true;
                    }
                }
            }

            next = {now.x + 1, now.y - 1};
            if (IsBound(next))
            {
                if (WU[now.x + 1][now.y - 1] != U && WR[now.x][now.y - 1] != R)
                {
                    if (discoverd[next.x][next.y] == false)
                    {
                        q.push(next);
                        discoverd[next.x][next.y] = true;
                    }
                }
            }

            next = {now.x + 1, now.y + 1};
            if (IsBound(next))
            {
                if (WU[now.x + 1][now.y + 1] != U && WR[now.x][now.y] != R)
                {
                    if (discoverd[next.x][next.y] == false)
                    {
                        q.push(next);
                        discoverd[next.x][next.y] = true;
                    }
                }
            }
        }
        p--;
    }
}

void scatterLEFT(int x, int y)
{
    queue<Point> q;
    y = y - 1;
    q.push({x, y});
    vector<vector<bool>> discoverd(r + 1, vector<bool>(c + 1, false));
    discoverd[x][y] = true;
    int p = 5;
    while (!q.empty())
    {
        int sz = q.size();
        if (p == 0)
            return;
        while (sz--)
        {
            Point now = q.front();
            q.pop();

            T[now.x][now.y] += p;

            Point next = {now.x, now.y - 1};
            if (IsBound(next))
            {
                if (WR[now.x][now.y - 1] != R)
                {
                    if (discoverd[next.x][next.y] == false)
                    {
                        q.push(next);
                        discoverd[next.x][next.y] = true;
                    }
                }
            }

            next = {now.x + 1, now.y - 1};
            if (IsBound(next))
            {
                if (WR[now.x + 1][now.y - 1] != R && WU[now.x+1][now.y] != U)
                {
                    if (discoverd[next.x][next.y] == false)
                    {
                        q.push(next);
                        discoverd[next.x][next.y] = true;
                    }
                }
            }

            next = {now.x - 1, now.y - 1};
            if (IsBound(next))
            {
                if (WR[now.x - 1][now.y - 1] != R && WU[now.x][now.y] != U)
                {
                    if (discoverd[next.x][next.y] == false)
                    {
                        q.push(next);
                        discoverd[next.x][next.y] = true;
                    }
                }
            }
        }
        p--;
    }
}

void scatterRIGHT(int x, int y)
{
    queue<Point> q;
    y = y + 1;
    q.push({x, y});
    vector<vector<bool>> discoverd(r + 1, vector<bool>(c + 1, false));
    discoverd[x][y] = true;
    int p = 5;
    while (!q.empty())
    {
        int sz = q.size();
        if (p == 0)
            return;
        while (sz--)
        {
            Point now = q.front();
            q.pop();

            T[now.x][now.y] += p;

            Point next = {now.x, now.y + 1};
            if (IsBound(next))
            {
                if (WR[now.x][now.y] != R)
                {
                    if (discoverd[next.x][next.y] == false)
                    {
                        q.push(next);
                        discoverd[next.x][next.y] = true;
                    }
                }
            }

            next = {now.x + 1, now.y + 1};
            if (IsBound(next))
            {
                if (WR[now.x + 1][now.y] != R && WU[now.x + 1][now.y] != U)
                {
                    if (discoverd[next.x][next.y] == false)
                    {
                        q.push(next);
                        discoverd[next.x][next.y] = true;
                    }
                }
            }

            next = {now.x - 1, now.y + 1};
            if (IsBound(next))
            {
                if (WR[now.x - 1][now.y] != R && WU[now.x][now.y] != U)
                {
                    if (discoverd[next.x][next.y] == false)
                    {
                        q.push(next);
                        discoverd[next.x][next.y] = true;
                    }
                }
            }
        }
        p--;
    }
}

void adapt(Point now, vector<vector<bool>>& visited, vector<vector<int>>& tmp)
{
    visited[now.x][now.y] = true;
    Point target;

    target = {now.x + 1, now.y};
    if (IsBound(target))
    {
        if (visited[target.x][target.y] == false)
        {
            if (WU[target.x][target.y] != U)
            {
                vector<Point> FromTo = {now, target};
                if (T[target.x][target.y] != T[now.x][now.y])
                {
                    if (T[target.x][target.y] > T[now.x][now.y])
                        ::swap(FromTo[0], FromTo[1]);

                    int &TFrom = T[FromTo[0].x][FromTo[0].y];
                    int &TTo = T[FromTo[1].x][FromTo[1].y];
                    int &TmpFrom = tmp[FromTo[0].x][FromTo[0].y];
                    int &TmpTo = tmp[FromTo[1].x][FromTo[1].y];
                    int p = (TFrom - TTo) / 4;

                    TmpFrom -= p;
                    TmpTo += p;
                }
            }
        }
    }
    target = {now.x, now.y + 1};
    if (IsBound(target))
    {
        if (visited[target.x][target.y] == false)
        {
            if (WR[now.x][now.y] != R)
            {
                vector<Point> FromTo = {now, target};
                if (T[target.x][target.y] != T[now.x][now.y])
                {
                    if (T[target.x][target.y] > T[now.x][now.y])
                        ::swap(FromTo[0], FromTo[1]);

                    int &TFrom = T[FromTo[0].x][FromTo[0].y];
                    int &TTo = T[FromTo[1].x][FromTo[1].y];
                    int &TmpFrom = tmp[FromTo[0].x][FromTo[0].y];
                    int &TmpTo = tmp[FromTo[1].x][FromTo[1].y];
                    int p = (TFrom - TTo) / 4;

                    TmpFrom -= p;
                    TmpTo += p;
                }
            }
        }
    }
    target = {now.x - 1, now.y};
    if (IsBound(target))
    {
        if (visited[target.x][target.y] == false)
        {
            if (WU[now.x][now.y] != U)
            {
                vector<Point> FromTo = {now, target};
                if (T[target.x][target.y] != T[now.x][now.y])
                {
                    if (T[target.x][target.y] > T[now.x][now.y])
                        ::swap(FromTo[0], FromTo[1]);

                    int &TFrom = T[FromTo[0].x][FromTo[0].y];
                    int &TTo = T[FromTo[1].x][FromTo[1].y];
                    int &TmpFrom = tmp[FromTo[0].x][FromTo[0].y];
                    int &TmpTo = tmp[FromTo[1].x][FromTo[1].y];
                    int p = (TFrom - TTo) / 4;

                    TmpFrom -= p;
                    TmpTo += p;
                }
            }
        }
    }
    target = {now.x, now.y - 1};
    if (IsBound(target))
    {
        if (visited[target.x][target.y] == false)
        {
            if (WR[target.x][target.y] != R)
            {
                vector<Point> FromTo = {now, target};
                if (T[target.x][target.y] != T[now.x][now.y])
                {
                    if (T[target.x][target.y] > T[now.x][now.y])
                        ::swap(FromTo[0], FromTo[1]);

                    int &TFrom = T[FromTo[0].x][FromTo[0].y];
                    int &TTo = T[FromTo[1].x][FromTo[1].y];
                    int &TmpFrom = tmp[FromTo[0].x][FromTo[0].y];
                    int &TmpTo = tmp[FromTo[1].x][FromTo[1].y];
                    int p = (TFrom - TTo) / 4;

                    TmpFrom -= p;
                    TmpTo += p;
                }
            }
        }
    }
}

bool oper()
{
    for (Fan f : fans)
    {
        int x = f.p.x;
        int y = f.p.y;
        switch (f.d)
        {
        case UP:
            scatterUP(x, y);
            break;
        case DOWN:
            scatterDOWN(x, y);
            break;
        case LEFT:
            scatterLEFT(x, y);
            break;
        case RIGHT:
            scatterRIGHT(x, y);
            break;
        default:
            break;
        }
    }

    vector<vector<bool>> visited(r+1, vector<bool>(c+1, false));
    vector<vector<int>> tmp = T;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            adapt({i, j}, visited, tmp);
        }
    }
    T = tmp;

    for (int i = 1; i <= r; i++)
    {
        if (T[i][1] != 0)
            T[i][1] -= 1;
        if (T[i][c] != 0)
            T[i][c] -= 1;
    }

    for (int i = 2; i <= c - 1; i++)
    {
        if (T[1][i] != 0)
            T[1][i] -= 1;
        
        if (T[r][i] != 0)
            T[r][i] -= 1;
    }

    bool ret = true;
    for (Point p : inq)
    {
        if (T[p.x][p.y] < k)
            ret = false;
    }

    return ret;
}

int main()
{
    FASTIO;

    cin >> r >> c >> k;

    T = vector<vector<int>>(r + 1, vector<int>(c + 1, 0));
    WU = vector<vector<int>>(r + 1, vector<int>(c + 1, 0));
    WR = vector<vector<int>>(r + 1, vector<int>(c + 1, 0));
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            int n;
            cin >> n;

            if (n == EMPTY)
            {

            }
            else if (n == INQURE)
            {
                inq.push_back({i, j});
            }
            else
            {
                fans.push_back({{i, j}, n});
            }
        }
    }

    int w;
    cin >> w;
    while (w--)
    {
        int x, y, t;
        cin >> x >> y >> t;
        if (t == 0)
        {
            WU[x][y] = U;
        }
        else
        {
            WR[x][y] = R;
        }
    }
    int ans = 1;
    while (!oper())
    {
        ans++;
        if (ans > 100)
            break;
    }
    
    cout << ans;

    return 0;
}