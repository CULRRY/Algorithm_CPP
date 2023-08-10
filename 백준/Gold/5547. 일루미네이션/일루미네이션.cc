#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dx_e[] = {-1, -1, -1, 0, 1, 0};
int dy_e[] = {-1, 0, 1, 1, 0, -1};

int dx_o[] = {0, -1, 0, 1, 1, 1};
int dy_o[] = {-1, 0, 1, 1, 0, -1};

int ans = 0;
void sol(int x, int y)
{
    visited[x][y] = true;
    for (int i = 0; i < 6; i++)
    {
        int nx, ny;
        if (y % 2 == 0)
        {
            nx = x + dx_e[i];
            ny = y + dy_e[i];
        }
        else
        {
            nx = x + dx_o[i];
            ny = y + dy_o[i];
        }

        if (nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1)
            continue;
        if (board[nx][ny] == 1)
        {
            ans++;
            continue;
        }
        if (visited[nx][ny] == true)
            continue;
        

        sol(nx, ny);
    }
}
int main()
{
    FASTIO;

    cin >> n >> m;
    board = vector<vector<int>>(n+2, vector<int>(m+2, 0));
    visited = vector<vector<bool>>(n + 2, vector<bool>(m + 2, 0));
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {

            cin >> board[i][j];
        }
    }

    sol(0, 0);

    cout << ans << endl;

    return 0;
}