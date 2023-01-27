#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int n, m;
vector<vector<int>> board;
vector<int> dy = {1, -1, 0, 0};
vector<int> dx = {0, 0, 1, -1};
vector<vector<bool>> visited;
void dfs(int y, int x)
{
    visited[y][x] = true;
    
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;

        if (visited[ny][nx] == true || board[ny][nx] == 0)
            continue;
        
        visited[ny][nx] = true;
        dfs(ny, nx);
    }
}
int CheckCount(int y, int x)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
            
        if (board[ny][nx] == 0)
            cnt++;
    }
    
    return cnt;
}

int go()
{
    vector<vector<int>> tmp(n, vector<int>(m, 0));
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != 0)
            {
                int cnt = CheckCount(i, j);
                tmp[i][j] = board[i][j] - cnt < 0 ? 0 : board[i][j] - cnt;
                if (tmp[i][j] != 0)
                    flag = true;
            }
        }
    }
    if (flag == false)
        return 0;
    board = tmp;
    visited.assign(n, vector<bool>(m, false));
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != 0 && visited[i][j] == false)
            {
                dfs(i, j);
                c++;
            }
        }
    }

    return c;
}

int main()
{
    FASTIO;
    cin >> n >> m;
    board.assign(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    int ans = 0;
    while (true)
    {
        ans++;
        int cnt = go();
        if (cnt == 0)
        {
            ans = 0;
            break;
        }

        if (cnt >= 2)
        {
            break;
        }
    }
    
    cout << ans;

    return 0;
}