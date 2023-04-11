#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int n, m;
int idx = 1;
int cnt = 0;
vector<vector<bool>> visited;
vector<vector<int>> board;
void dfs(int y, int x)
{

    board[y][x] = idx;
    visited[y][x] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if (visited[ny][nx] == true)
            continue;
        if (board[ny][nx] == 0)
            continue;
    
        dfs(ny, nx);
    
        
    }
}

int main()
{
    FASTIO;


    cin >> n >> m;
    board = vector<vector<int>>(n, vector<int>(m, 0));

    for (auto& v : board)
        for (int& i : v)
            cin >> i;

    vector<int> sizeIndex(1, 0);
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
                continue;
            if (visited[i][j] == true)
                continue;
            
            cnt = 0;
            dfs(i, j);
            idx++;
            sizeIndex.push_back(cnt);
        }
    }

    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 0)
            {
                int shape = 1;
                vector<bool> isUsed(sizeIndex.size(), false);
                for (int d = 0; d < 4; d++)
                {
                    int ny = i + dy[d], nx = j + dx[d];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                        continue;
                    if (board[ny][nx] == 0)
                        continue;
                    if (isUsed[board[ny][nx]] == true)
                        continue;
                    
                    isUsed[board[ny][nx]] = true;
                    shape += sizeIndex[board[ny][nx]];
                }

                ans = std::max(shape, ans);
            }
        }
    }

    cout << ans << endl;

    return 0;
}