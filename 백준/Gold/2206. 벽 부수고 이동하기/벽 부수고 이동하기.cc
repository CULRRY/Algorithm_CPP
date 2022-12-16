#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int y, x;
    int left;
};

const vector<Point> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int BFS(vector<vector<char>> &adj, int n, int m)
{
    queue<Point> q;
    q.push({1, 1, 1});
    vector<vector<vector<int>>> visited(n + 1, vector<vector<int>>(m + 1, vector<int>(2, 0)));
    visited[1][1][1] = 1;
    int dist = 0;

    while (!q.empty())
    {
        int sz = q.size();
        dist++;
        for (int s = 0; s < sz; s++)
        {
            Point now = q.front();
            q.pop();

            if (now.y == n && now.x == m)
            {
                return visited[now.y][now.x][now.left];
            }

            for (int i = 0; i < dir.size(); i++)
            {
                Point next = {now.y + dir[i].y, now.x + dir[i].x, now.left};
                if (next.y < 1 || next.y > n)
                    continue;
                if (next.x < 1 || next.x > m)
                    continue;

                if (adj[next.y][next.x] == '1' && next.left == 1)
                {
                    visited[next.y][next.x][next.left - 1] = visited[now.y][now.x][next.left] + 1;
                    q.push({next.y, next.x, next.left-1});
                }

                if (adj[next.y][next.x] == '0' && visited[next.y][next.x][next.left] == 0)
                {
                    visited[next.y][next.x][next.left] = visited[now.y][now.x][next.left] + 1;
                    q.push({next.y, next.x, next.left});
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n + 1, vector<char>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> adj[i][j];
        }
    }

    int result = BFS(adj, n, m);

    cout << result;
    return 0;
}