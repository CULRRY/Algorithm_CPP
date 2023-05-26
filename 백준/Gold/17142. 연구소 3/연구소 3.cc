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


int n, m;
vector<Point> virus;
vector<Point> canVirus;
vector<vector<int>> lab;
int ans = INT_MAX;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int rest = 0;

int check()
{
    vector<vector<int>> tmp = lab;
    vector<vector<bool>> discoverd(n, vector<bool>(n, false));
    int tr = rest;
    queue<Point> q;
    for (Point p : virus)
    {
        q.push(p);
        discoverd[p.y][p.x] = true;
    }
    
    int cnt = -1;

    while (!q.empty())
    {
        int sz = q.size();
        cnt++;
        while (sz--)
        {
            Point now = q.front();
            q.pop();
            if (tmp[now.y][now.x] == 0)
                tr--;

            if (tr <= 0)
                return cnt;
            
            for (int i = 0; i < 4; i++)
            {
                Point next = {now.y + dy[i], now.x + dx[i]};
                if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n)
                    continue;
                
                if (discoverd[next.y][next.x] == true)
                    continue;
                if (tmp[next.y][next.x] == 1)
                    continue;
                
                q.push(next);
                discoverd[next.y][next.x] = true;
            }
        }
    }


    return INT_MAX;
}


void bt(int depth, int idx)
{
    if (depth == m)
    {
        ans = std::min(check(), ans);
        return;
    }

    for (int i = idx + 1; i < canVirus.size(); i++)
    {
        virus[depth] = canVirus[i];
        bt(depth + 1, i);
    }
}

int main()
{
    FASTIO;

    cin >> n >> m;
    lab = vector<vector<int>>(n, vector<int>(n, 0));
    virus = vector<Point>(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 2)
            {
                canVirus.push_back({i, j});
            }
            else if (lab[i][j] == 1)
            {
                continue;
            }
            else
            {
                rest++;
            }
        }
    }

    bt(0, -1);

    if (ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}