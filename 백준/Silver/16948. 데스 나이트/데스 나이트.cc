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

int n;
vector<int> dy = {-2, -2, 0, 0, 2, 2};
vector<int> dx = {-1, 1, -2, 2, -1, 1};

int bfs(int y, int x, int ey, int ex)
{
    vector<vector<bool>> discovered(n, vector<bool>(n, 0));
    queue<Point> q;
    q.push({y, x});
    discovered[y][x] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        for (int s = 0; s < sz; s++)
        {
            Point now = q.front();
            q.pop();
            if (now.y == ey && now.x == ex)
                return cnt;
            for (int i = 0; i < 6; i++)
            {
                Point next = {now.y + dy[i], now.x + dx[i]};
                if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)
                    continue;
                if (discovered[next.y][next.x] == true)
                    continue;
                
                discovered[next.y][next.x] = true;
                q.push(next);
            }
        }
        cnt++;
    }
    
    return -1;
}

int main()
{
    FASTIO;

     
    cin >> n;
    int sy, sx, ey, ex;
    cin >> sy >> sx >> ey >> ex;
    cout << bfs(sy, sx, ey, ex);

    return 0;
}