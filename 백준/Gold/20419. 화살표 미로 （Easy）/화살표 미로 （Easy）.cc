#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
enum
{
    U, R, D, L,
};
vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};
int r, c, k;
int rscroll;
int lscroll;
bool answer = false;
bool IsBounded(int y, int x)
{
    if (y < 0 || y >= r || x < 0 || x >= c)
        return false;
    
    return true;
}
vector<vector<bool>> visited;
void dfs(int y, int x, int rscroll, int lscroll, vector<vector<int>> board)
{
    if (y == r - 1 && x == c - 1)
    {
        answer = true;
        return;
    }
    visited[y][x] = true;
    int d = board[y][x];
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (IsBounded(ny, nx))
    {
        if (visited[ny][nx] == false)
        {
            dfs(ny, nx, rscroll, lscroll, board);
        }
        
    }
    
    if (rscroll >= 1)
    {
        int rd = d == L ? U : d + 1;
        ny = y + dy[rd];
        nx = x + dx[rd];
        board[y][x] = rd;
        if (IsBounded(ny, nx))
        {
            if (visited[ny][nx] == false)
                dfs(ny, nx, rscroll-1, lscroll, board);
        }
    }

    if (lscroll >= 1)
    {
        int ld = d == U ? L : d - 1;
        ny = y + dy[ld];
        nx = x + dx[ld];
        board[y][x] = ld;
        if (IsBounded(ny, nx))
        {
            if (visited[ny][nx] == false)
                dfs(ny, nx, rscroll, lscroll-1, board);
        }
    }
}

int main()
{
    FASTIO;

    cin >> r >> c >> k;
    rscroll = lscroll = k;
    vector<vector<int>> board;
    visited.assign(r, vector<bool>(c, 0));
    board.assign(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char c;
            int d;
            cin >> c;
            if (c == 'U')
                d = U;
            else if (c == 'D')
                d = D;
            else if (c == 'L')
                d = L;
            else if (c == 'R')
                d = R;

            board[i][j] = d;
        }
    }

    dfs(0, 0, rscroll, lscroll, board);

    if (answer)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}