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

int n, m, ans = 987654321;
vector<vector<int>> lab;
vector<Point> virusPoints;
vector<Point> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<Point> virus;
int bfs()
{
    queue<Point> q;
    vector<vector<bool>> discoverd(n, vector<bool>(n, false));
    for (auto& p : virus)
    {   
        q.push(p);
        discoverd[p.y][p.x] = true;
    }
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            Point now = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                Point next = {now.y + direction[i].y, now.x + direction[i].x};
                if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)
                    continue;
                if (discoverd[next.y][next.x] == true)
                    continue;
                if (lab[next.y][next.x] == 1)
                    continue;
                
                discoverd[next.y][next.x] = true;
                q.push(next);
            }
        }
        cnt++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (lab[i][j] != 1 && discoverd[i][j] == false)
                return -1;
        }
    }

    return cnt-1;
}

vector<bool> isUsed;
void bt(int depth, int idx)
{
    if (depth == m)
    {
        int result = bfs();
        if (result == -1)
            return;
        else
            ans = std::min(result, ans);
        
        return;
    }

    for (int i = idx + 1; i < virusPoints.size(); i++)
    {
        if (isUsed[i] == true)
            continue;
        
        isUsed[i] = true;
        virus[depth] = virusPoints[i];
        bt(depth+1, i);
        isUsed[i] = false;
    }
}

int main()
{
    FASTIO;

    cin >> n >> m;
    lab = vector<vector<int>>(n, vector<int>(n, 0));
    virus = vector<Point>(m, {0,0});
    virusPoints = vector<Point>();
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 2)
                virusPoints.push_back({i, j});
        }
    }
    isUsed.assign(virusPoints.size(), false);
    bt(0, -1);
    if (ans == 987654321)
        cout << -1;
    else
        cout << ans;
    return 0;
}