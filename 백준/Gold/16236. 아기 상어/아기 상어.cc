#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int y, x;
};
vector<Point> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int t = 0;
int N;
int size = 2;

Point bfs(vector<vector<int>> &pool, Point start)
{
    queue<Point> q;
    vector<vector<bool>> discoverd;
    discoverd.assign(N, vector<bool>(N, 0));
    vector<Point> v;
    q.push(start);
    pool[start.y][start.x] = 0;
    discoverd[start.y][start.x] = 1;
    int depth = 0;
    int minDepth = INT_MAX;
    Point minPoint;
    bool lock = false;
    while (!q.empty())
    {
        int sz = q.size();
        for (int s = 0; s < sz; s++)
        {
            Point now = q.front();
            q.pop();
            if (pool[now.y][now.x] < ::size && pool[now.y][now.x] > 0)
            {
                if (!lock)
                {
                    minDepth = depth;
                    minPoint = now;
                    lock = true;
                }
                else
                {
                    if (minDepth < depth)
                    {
                        t += minDepth;
                        return minPoint;
                    }

                    else if (minDepth == depth)
                    {
                        if (minPoint.y > now.y)
                        {
                            minPoint = now;
                        }
                        else if (minPoint.y == now.y)
                        {
                            if (minPoint.x > now.x)
                                minPoint = now;
                        }
                    }
                }                
            }

            for (int i = 0; i < dir.size(); i++)
            {
                Point next = {now.y + dir[i].y, now.x + dir[i].x};
                if (next.x >= 0 && next.x < N && next.y >= 0 && next.y < N && pool[next.y][next.x] <= ::size && discoverd[next.y][next.x] == 0)
                {
                    q.push(next);
                    discoverd[next.y][next.x] = 1;
                }
            }
        }
        if (lock)
        {
            t += minDepth;
            return minPoint;
        }
        depth++;
    }

    return Point{-1, -1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> N;

    Point start;
    vector<vector<int>> pool;
    pool.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> pool[i][j];
            if (pool[i][j] == 9)
            {
                start.y = i;
                start.x = j;
            }
        }
    }

    int c = 0;
    while (true)
    {
        start = bfs(pool, start);
        if (start.y == -1 && start.x == -1)
            break;
        
        c++;
        if (c == ::size)
        {
            ::size++;
            c = 0;
        }
        
    }

    cout << t << "\n";

    return 0;
}