#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n, m;
vector<vector<char>> armys;
vector<vector<bool>> visited;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int W = 0, B = 0;
int cnt = 0;
void dfs(int y, int x, char mark)
{
    visited[y][x] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx > m)
            continue;
        if (visited[ny][nx] == true)
            continue;
        if (armys[ny][nx] != mark)
            continue;

        dfs(ny, nx, mark);
    }
}

int main()
{
    FASTIO;

    cin >> m >> n;
    armys = vector<vector<char>>(n, vector<char>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> armys[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
                continue;
            
            cnt = 0;

            if (armys[i][j] == 'W')
            {
                dfs(i, j, 'W');
                W += cnt * cnt;
            }
            else
            {
                dfs(i, j, 'B');
                B += cnt * cnt;
            }
        }
    }

    cout << W << " " << B << endl;

    return 0;
}