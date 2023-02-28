#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

struct Point
{
    int y, x;
};

vector<Point> d = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int bfs()
{
    int l;
    cin >> l;
    vector<vector<int>> board(l, vector<int>(l, 0));
    vector<vector<bool>> discoverd(l, vector<bool>(l, false));
    Point start;
    Point target;
    cin >> start.y >> start.x >> target.y >> target.x;
    queue<Point> q;
    q.push(start);
    discoverd[start.y][start.x] = true;
    int cnt = 0;

    while (!q.empty())
    {
        int sz = q.size();
        
        for (int c = 0; c < sz; c++)
        {
            Point now = q.front();
            q.pop();
            if (now.y == target.y && now.x == target.x)
                return cnt;
            
            for (int i = 0; i < 8; i++)
            {
                Point next = {now.y + d[i].y, now.x + d[i].x};
                if (next.y < 0 || next.y >= l || next.x < 0 || next.x >= l)
                    continue;
                if (discoverd[next.y][next.x] == true)
                    continue;
                
                discoverd[next.y][next.x] = true;
                q.push(next);
            }
        }
        cnt++;
    }

    return 0;
}

int main()
{
    FASTIO;

    int tc;
    cin >> tc;
    while (tc--)
    {
        cout << bfs() << endl;
    }

    return 0;
}