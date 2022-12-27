#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

struct Point
{
    int y, x;
};

int n, m;
vector<vector<char>> board;
vector<vector<bool>> visited;
vector<vector<bool>> finished;
int cycle = 0;

void DFS(Point start)
{
    Point now = start;
    Point next;
    switch (board[now.y][now.x])
    {
    case 'D':
        next = {now.y + 1, now.x};
        break;
    
    case 'U':
        next = {now.y - 1, now.x};
        break;

    case 'L':
        next = {now.y, now.x - 1};
        break;

    case 'R':
        next = {now.y, now.x + 1};
        break;    

    default:
        break;
    }

    if (visited[next.y][next.x])
    {
        if (!finished[next.y][next.x])
        {
            cycle++;
        }
    }
    else
    {
        visited[next.y][next.x] = true;
        DFS(next);
    }

    finished[now.y][now.x] = true;
}

int main()
{
    FASTIO;


    cin >> n >> m;

    board = vector<vector<char>>(n, vector<char>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    finished = vector<vector<bool>>(n, vector<bool>(m, false));
    
    for (auto& row : board)
    {
        for (char& c : row)
        {
            cin >> c;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!finished[i][j])
            {
                visited[i][j] = true;
                DFS({i, j});
            }
        }
    }

    cout << cycle;

    return 0;
}