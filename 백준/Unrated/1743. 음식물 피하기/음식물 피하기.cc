#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n, m, k;
int cnt = 0;
vector<vector<int>> ground;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

void dfs(int y, int x)
{
    ground[y][x] = 2;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny <= 0 || ny > n || nx <= 0 || nx > m)
            continue;
        if (ground[ny][nx] != 1)
            continue;
        
        dfs(ny, nx);
    }
}

int main()
{
    FASTIO;

    cin >> n >> m >> k;
    ground = vector<vector<int>> (n+1, vector<int>(m+1, 0));

    while (k--)
    {
        int y, x;
        cin >> y >> x;
        ground[y][x] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ground[i][j] == 1)
            {
                cnt = 0;
                dfs(i, j);
                ans = std::max(ans, cnt);
            }
        }
    }

    cout << ans;
            

    return 0;
}