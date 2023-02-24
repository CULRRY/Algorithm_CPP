#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
vector<vector<int>> area;
vector<vector<bool>> visited;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int cnt = 0;
int n;
void dfs(int y, int x, int limit)
{
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;
        if (visited[ny][nx] == true)
            continue;
        if (area[ny][nx] <= limit)
            continue;
        
        dfs(ny, nx, limit);
    }
}


int main()
{
    FASTIO;

    cin >> n;
    area = vector<vector<int>>(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> area[i][j];
        }
    } 

    int ans = 0;
    for (int c = 0; c <= 100; c++)
    {
        visited = vector<vector<bool>>(n, vector<bool>(n, false));
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == true)
                    continue;
                if (area[i][j] <= c)
                    continue;
                dfs(i, j, c);
                cnt++;
            }
        }

        ans = std::max(cnt, ans);
    }

    cout << ans << endl;
    return 0;
}