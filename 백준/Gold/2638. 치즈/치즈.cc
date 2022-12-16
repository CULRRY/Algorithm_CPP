#include <bits/stdc++.h>
using namespace std;

using vvi = vector<vector<int>>;
int n, m;

struct Point
{
    int y, x;
};

const vector<Point> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isBounded(const Point &p)
{
    if (p.x < 0 || p.x >= m || p.y < 0 || p.y >= n)
        return false;

    return true;
}

void BFS(vvi &v)
{
    queue<Point> q;
    q.push({0, 0});
    vvi visited(n, vector<int>(m, 0));

    while (!q.empty())
    {
        Point now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Point next = {now.y + dir[i].y, now.x + dir[i].x};
            if (!isBounded(next))
                continue;

            if (visited[next.y][next.x])
                continue;

            if (v[next.y][next.x] == 1)
                continue;

            v[next.y][next.x] = 2;
            q.push(next);
            visited[next.y][next.x] = 1;
        }
    }
}

int checkTouch(vvi &v, int y, int x)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        if (!isBounded({y, x}))
            continue;
        Point next = {y + dir[i].y, x + dir[i].x};
        if (v[next.y][next.x] == 2)
            cnt++;
    }

    return cnt;
}

void melt(vvi &v, int &numc)
{
    vvi tmp(v);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 1)
            {
                if (checkTouch(v, i, j) >= 2)
                {
                    tmp[i][j] = 2;
                    numc--;
                }
            }
        }
    }
    v = tmp;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vvi v(n, vector<int>(m, 0));
    int numc = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 1)
                numc++;
        }
    }
    int result = 0;
    while (numc)
    {
        BFS(v);
        melt(v, numc);
        result++;
    }

    cout << result;

    return 0;
}