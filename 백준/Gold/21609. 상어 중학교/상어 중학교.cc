#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

enum
{
    EMPTY = -5,
    RAINBOW = 0,
    BLACK = -1,
};

struct Group
{
    int y, x;
    int r;
    int size;
};

int n, m;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
vector<vector<int>> board;
vector<vector<bool>> visitedTotal(n, vector<bool>(n, false));
void dfs(int y, int x, int color, Group& g, vector<vector<bool>>& visited)
{
    visited[y][x] = true;
    g.size++;
    if (board[y][x] != RAINBOW)
        visitedTotal[y][x] = true;
    else
        g.r++;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;
        if (visited[ny][nx] == true)
            continue;
        if (board[ny][nx] != color)
        {
            if (board[ny][nx] != RAINBOW)
                continue;
        }
        
        dfs(ny, nx, color, g, visited);
    }
}

void Delete(int y, int x, int color)
{
    board[y][x] = EMPTY;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;
        if (board[ny][nx] != color)
        {
            if (board[ny][nx] != RAINBOW)
                continue;
        }

        Delete(ny, nx, color);
    }
}

void Gravity()
{
    for (int c = 0; c < n; c++)
    {
        for (int r = n - 1; r >= 0; r--)
        {
            if (board[r][c] == EMPTY)
                continue;
            if (board[r][c] == BLACK)
                continue;
            
            int tr = r;
            for (int i = r + 1; i < n; i++)
            {
                if (board[i][c] != EMPTY)
                    break;
                tr = i;
            }

            ::swap(board[tr][c], board[r][c]);
        }
    }
}

void Rotate()
{
    vector<vector<int>> tmp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[i][j] = board[j][n - i - 1];
        }
    }

    board = tmp;
}

void print_board()
{
    for (auto v : board)
    {
        for (auto i : v)
        {
            if (i == EMPTY)
                cout << "E";
            else if (i == RAINBOW)
                cout << "R";
            else if (i == BLACK)
                cout << "B";
            else
                cout << i;
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int play()
{
    int score = 0;

    while (true)
    {

        visitedTotal = vector<vector<bool>>(n, vector<bool>(n, false));
        vector<Group> groups;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visitedTotal[i][j] == true)
                    continue;
                if (board[i][j] == RAINBOW)
                    continue;
                if (board[i][j] == BLACK)
                    continue;
                if (board[i][j] == EMPTY)
                    continue;

                vector<vector<bool>> visitedLocal(n, vector<bool>(n, false));
                Group g = {i, j, 0, 0};
                dfs(i, j, board[i][j], g, visitedLocal);

                if (g.size >= 2)
                    groups.push_back(g);
            }
        }

        if (groups.empty())
            return score;

        Group selected = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};

        for (Group g : groups)
        {
            if (g.size < selected.size)
                continue;
            else if (g.size == selected.size)
            {
                if (g.r < selected.r)
                    continue;
                else if (g.r == selected.r)
                {
                    if (g.y < selected.y)
                        continue;
                    else if (g.y == selected.y)
                    {
                        if (g.x < selected.x)
                            continue;
                    }
                }   
            }
            
            selected = g;
        }

        Delete(selected.y, selected.x, board[selected.y][selected.x]);

        score += selected.size * selected.size;
        
        Gravity();
        Rotate();
        Gravity();
    }
    
    return -1;
}

int main()
{
    FASTIO;

    cin >> n >> m;
    board = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << play();

    return 0;
}