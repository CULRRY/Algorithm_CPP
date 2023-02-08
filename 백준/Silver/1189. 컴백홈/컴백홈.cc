#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int r, c, k;
int answer = 0;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void dfs(vector<vector<char>>& board, vector<vector<bool>> visited, int y, int x, int dist)
{
    if (dist > k)
        return;
    if (dist == k && y == 1 && x == c)
    {
        answer++;
        return;
    }
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx <= 0 || nx > c || ny <= 0 || ny > r)
            continue;
        if (board[ny][nx] == 'T')
            continue;
        if (visited[ny][nx] == true)
            continue;
        
        dfs(board, visited, ny, nx, dist + 1);
    }
}

int main()
{
    FASTIO;

    cin >> r >> c >> k;
    vector<vector<char>> board(r+1, vector<char>(c+1));
    vector<vector<bool>> visited(r+1, vector<bool>(c+1, false));
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> board[i][j];
        }
    }

    dfs(board, visited, r, 1, 1);

    cout << answer << endl;

    return 0;
}