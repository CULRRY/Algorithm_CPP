#include <bits/stdc++.h>
using namespace std;
int M, N;
struct Point
{
    int y, x;
};

vector<Point> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(vector<vector<int>> &v)
{
    queue<Point> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (v[i][j] == 1)
                q.push(Point{i,j});
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int sz = q.size();
        for (int s = 0; s < sz; s++)
        {
            Point now = q.front();
            q.pop();
            for (int i = 0; i < direction.size(); i++)
            {
                Point next = {now.y + direction[i].y, now.x + direction[i].x};

                if (next.x >= 0 && next.x < M && next.y >= 0 && next.y < N && v[next.y][next.x] == 0)
                {
                    q.push(next);
                    v[next.y][next.x] = 1;
                }
            }
        }
        count++;
    }

    return count-1;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;

    vector<vector<int>> v;
    v.assign(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> v[i][j];
        }
    }

    int result = bfs(v);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (v[i][j] == 0)
            {
                result = -1;
                i = N;
                break;
            }
        }
    }

    cout << result << "\n";

    return 0;
}