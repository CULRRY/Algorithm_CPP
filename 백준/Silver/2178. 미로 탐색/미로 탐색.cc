#include <bits/stdc++.h>
using namespace std;
int N, M;
struct point
{
    int y, x;

    point operator+(const point &p)
    {
        return point{y + p.y, x + p.x};
    }

    bool operator==(const point &p)
    {
        return x == p.x && y == p.y;
    }
};

int bfs(vector<vector<char>> &m, point start, point target)
{
    vector<point> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> discoverd;
    discoverd.assign(N + 1, vector<int>(M + 1, 0));
    int count = 0;
    queue<point> q;
    q.push(start);
    discoverd[start.y][start.x] = 1;

    while (!q.empty())
    {
        int sz = q.size();
        count++;
        for (int j = 0; j < sz; j++)
        {
            point now = q.front();
            q.pop();
            for (int i = 0; i < direction.size(); i++)
            {
                point next = now + direction[i];
                if (next == target)
                {
                    return ++count;
                }

                if (next.x >= 1 && next.y >= 1 && next.x <= M && next.y <= N)
                {
                    if (discoverd[next.y][next.x] == 0 && m[next.y][next.x] == '1')
                    {
                        q.push(next);
                        discoverd[next.y][next.x] = 1;
                    }
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

    cin >> N >> M;

    vector<vector<char>> maze;
    maze.assign(N + 1, vector<char>(M + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> maze[i][j];
        }
    }

    cout << bfs(maze, point{1, 1}, point{N, M});

    return 0;
}