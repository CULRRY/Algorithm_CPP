#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

struct Fish
{
    int x, y, d;
};


int ans = 0;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

bool IsBound(int x, int y)
{
    if (x < 0 || x >= 4)
        return false;
    if (y < 0 || y >= 4)
        return false;
    
    return true;
}

void bt(int sx, int sy, int sd, int sum, vector<Fish> f, vector<vector<int>> pool)
{
    for (int i = 1; i <= 16; i++)
    {
        if (f[i].d == -1)
            continue;
        
        int nx = f[i].x + dx[f[i].d];
        int ny = f[i].y + dy[f[i].d];

        while ((ny == sy && nx == sx) || !IsBound(nx, ny))
        {
            f[i].d = (f[i].d + 1) % 8;
            nx = f[i].x + dx[f[i].d];
            ny = f[i].y + dy[f[i].d];
        }
        
        int cn = pool[nx][ny];

        ::swap(pool[nx][ny], pool[f[i].x][f[i].y]);
        f[cn].x = f[i].x;
        f[cn].y = f[i].y;
        f[i].x = nx;
        f[i].y = ny;
    }

    int nx = sx + dx[sd];
    int ny = sy + dy[sd];

    bool flag = true;
    while (IsBound(ny, nx))
    {
        if (f[pool[nx][ny]].d != -1)
        {
            flag = false;
            int nd = f[pool[nx][ny]].d;
            f[pool[nx][ny]].d = -1;
            bt(nx, ny, nd, sum + pool[nx][ny], f, pool);
            f[pool[nx][ny]].d = nd;
        }

        nx += dx[sd];
        ny += dy[sd];
    }

    if (flag)
    {
        ans = std::max(ans, sum);
        return;
    }
}


int main()
{
    FASTIO;
    vector<Fish> f;
    vector<vector<int>> pool;
    f = vector<Fish>(17);
    pool = vector<vector<int>>(4, vector<int>(4, 0));

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int n, d;
            cin >> n >> d;
            f[n].d = d - 1;
            f[n].x = i;
            f[n].y = j;
            pool[i][j] = n;
        }
    }
    int sd = f[pool[0][0]].d;
    f[pool[0][0]].d = -1;
    bt(0, 0, sd, pool[0][0], f, pool);

    cout << ans << endl;

    return 0;
}