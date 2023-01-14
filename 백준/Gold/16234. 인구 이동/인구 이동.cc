#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);
#define endl "\n"

using namespace std;

struct Point
{
    int y, x;
};
int n, l, r;
const vector<Point> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool isBounded(Point p)
{
    if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= n)
        return false;
    
    return true;
}
int sum = 0;
int cnt = 0;
vector<vector<bool>> visited;
queue<Point> q;
bool isEnd = true;
void dfs(vector<vector<int>>& country, Point now)
{
    q.push(now);
    sum += country[now.y][now.x];
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        Point next = {now.y + d[i].y, now.x + d[i].x};
        if (!isBounded(next))
            continue;
        if (visited[next.y][next.x])
            continue;

        int diff = abs(country[now.y][now.x] - country[next.y][next.x]);
        if (diff >= l && diff <= r)
        {
            isEnd = false;
            visited[next.y][next.x] = true;
            dfs(country, next);
        }
    }
}
int main()
{
    FASTIO;


    cin >> n >> l >> r;
    vector<vector<int>> country(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> country[i][j];
        }
    }

    int ans = 0;
    while (true)
    {
        isEnd = true;
        visited = vector<vector<bool>>(n, vector<bool>(n, 0));
        vector<vector<int>> tmp(country);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j])
                    continue;

                sum = 0;
                cnt = 0;
                visited[i][j] = true;
                dfs(country, {i, j});

                
                if (q.size() == 1)
                {
                    q.pop();
                    continue;
                }

                int ret = sum / cnt;
                while (!q.empty())
                {
                    Point p = q.front();
                    q.pop();
                    tmp[p.y][p.x] = ret;
                }
            }
        }
        country = tmp;
        if (isEnd)
            break;
        ans++;
    }

    cout << ans;
    

    return 0;
}