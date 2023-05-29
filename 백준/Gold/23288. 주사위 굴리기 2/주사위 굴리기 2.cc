#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

enum
{
    U, D, F, B, L, R
};

enum
{
    E, S, W, N
};

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int n, m, k;
vector<int> dice = {1, 6, 5, 2, 4, 3};
vector<vector<int>> board;
int y = 1;
int x = 1;
int d = E;
int score = 0;

void roll()
{
    vector<int> tmp = dice;
    switch (d)
    {
    case E:
        tmp[U] = dice[L];
        tmp[R] = dice[U];
        tmp[D] = dice[R];
        tmp[L] = dice[D];
        break;
    case S:
        tmp[U] = dice[B];
        tmp[B] = dice[D];
        tmp[D] = dice[F];
        tmp[F] = dice[U];
        break;
    case W:
        tmp[U] = dice[R];
        tmp[R] = dice[D];
        tmp[D] = dice[L];
        tmp[L] = dice[U];
        break;
    case N:
        tmp[U] = dice[F];
        tmp[F] = dice[D];
        tmp[D] = dice[B];
        tmp[B] = dice[U];
        break;
    default:
        break;
    }

    dice = tmp;
}


vector<vector<bool>> visited;
void get_score(int y, int x, int t, int& score)
{
    visited[y][x] = true;
    score += t;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny <= 0 || ny > n || nx <= 0 || nx > m)
            continue;
        if (visited[ny][nx])
            continue;
        if (board[ny][nx] != t)
            continue;
        
        get_score(ny, nx, t, score);
    }
}

void move()
{
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (ny <= 0 || ny > n || nx <= 0 || nx > m)
    {
        d = (d+2)%4;
        ny = y + dy[d];
        nx = x + dx[d];
    }
    roll();
    visited = vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));
    int plus = 0;
    get_score(ny, nx, board[ny][nx], plus);

    score += plus;

    if (dice[D] > board[ny][nx])
        d = (d+1)%4;
    else if (dice[D] < board[ny][nx])
        d = d == 0 ? 3 : d - 1;
    
    y = ny;
    x = nx;
}

int main()
{
    FASTIO;

    cin >> n >> m >> k;
    board = vector<vector<int>>(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> board[i][j];
        }
    }

    while (k--)
    {
        move();
    }
    
    cout << score;

    return 0;
}