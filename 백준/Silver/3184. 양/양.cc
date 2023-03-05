#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int r, c;
vector<vector<char>> board;
vector<vector<bool>> visited;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

int wolf = 0;
int sheep = 0;
int v = 0;
int o = 0;
void dfs(int y, int x)
{
    visited[y][x] = true;
    if (board[y][x] == 'v')
        v++;
    if (board[y][x] == 'o')
        o++;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
            continue;
        if (visited[ny][nx] == true)
            continue;
        if (board[ny][nx] == '#')
            continue;
        
        dfs(ny, nx);
    }
}
int main()
{
    FASTIO;

    cin >> r >> c;
    board = vector<vector<char>>(r, vector<char>(c));
    visited = vector<vector<bool>>(r, vector<bool>(c, false));  

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'v')
                wolf++;
            if (board[i][j] == 'o')
                sheep++;
        } 
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == '#')
                continue;
            v = 0;
            o = 0;
            dfs(i, j);
            if (v >= o)
                sheep -= o;
            else
                wolf -= v;
        }
    }

    cout << sheep << " " << wolf << endl;

    return 0;
}