#include <bits/stdc++.h>
using namespace std;
int r, c, t;

struct Point
{
    int y, x;
};

vector<Point> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

void Clean(vector<vector<int>> &v, Point cl)
{
    Point lowCleaner = cl;
    Point upCleaner = cl;
    upCleaner.y -= 1;
    for (int i = lowCleaner.y + 2; i < r; i++)
    {
        v[i - 1][0] = v[i][0];
    }
    for (int i = 1; i < c; i++)
    {
        v[r - 1][i - 1] = v[r - 1][i];
    }
    for (int i = r - 2; i >= lowCleaner.y; i--)
    {
        v[i + 1][c - 1] = v[i][c - 1];
    }
    for (int i = c - 2; i >= 1; i--)
    {
        v[lowCleaner.y][i + 1] = v[lowCleaner.y][i];
    }

    for (int i = upCleaner.y - 2; i >= 0; i--)
    {
        v[i + 1][0] = v[i][0];
    }
    for (int i = 1; i < c; i++)
    {
        v[0][i - 1] = v[0][i];
    }
    for (int i = 1; i <= upCleaner.y; i++)
    {
        v[i - 1][c - 1] = v[i][c - 1];
    }
    for (int i = c - 2; i >= 1; i--)
    {
        v[upCleaner.y][i + 1] = v[upCleaner.y][i];
    }
    v[upCleaner.y][upCleaner.x + 1] = 0;
    v[lowCleaner.y][lowCleaner.x + 1] = 0;
}

void Spread(vector<vector<int>> &v, Point cleaner)
{
    queue<Point> q;
    vector<vector<int>> tmp(v);

    int cnt = 0;
    while (cnt < t)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (v[i][j] > 0)
                {
                    q.push({i, j});
                }
            }
        }
        tmp = v;
        int sz = q.size();
        for (int s = 0; s < sz; s++)
        {
            Point now = q.front();
            q.pop();
            int dust = v[now.y][now.x];

            for (int i = 0; i < dir.size(); i++)
            {
                Point next = {now.y + dir[i].y, now.x + dir[i].x};
                if (next.x >= 0 && next.x < c && next.y >= 0 && next.y < r && v[next.y][next.x] != -1)
                {
                    tmp[now.y][now.x] -= dust / 5;
                    tmp[next.y][next.x] += dust / 5;
                }
            }
        }
        v = tmp;
        Clean(v, cleaner);
        cnt++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> t;
    vector<vector<int>> v(r, vector<int>(c, 0));
    Point cleaner;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == -1)
            {
                cleaner = {i, j};
            }
        }
    }

    Spread(v, cleaner);
    int cnt = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (v[i][j] != -1)
                cnt += v[i][j];
        }
    }

    cout << cnt;

    return 0;
}