#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n, m;
bool cycle = false;
vector<vector<int>> visited;
vector<vector<bool>> finished;
vector<vector<char>> board;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void dfs(int y, int x, int cnt, char norm)
{
    visited[y][x] = cnt;

    for (int d = 0; d < 4; d++)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;

        if (board[ny][nx] != norm)
            continue;
        if (visited[ny][nx] != -1)
        {
            if (finished[ny][nx] == false)
            {
                int gap = cnt - visited[ny][nx] + 1;
                if (gap >= 4)
                    cycle = true;
            }
            continue;
        }

        dfs(ny, nx, cnt+1, norm);
    }

    finished[y][x] = true;
}

int main()
{
    FASTIO;



    cin >> n >> m;
    visited = vector<vector<int>>(n, vector<int>(m, -1));
    finished = vector<vector<bool>>(n, vector<bool>(m, false));
    board = vector<vector<char>>(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (cycle == true)
            {
                cout << "Yes" << endl;
                return 0;
            }

            if (visited[i][j] != -1)
                continue;
            
            dfs(i, j, 0, board[i][j]);

        }
    }

    cout << "No" << endl;

    return 0;
}