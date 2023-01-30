#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

enum
{
    E = 1,
    W,
    N,
    S,
};

enum
{
    TOP, BOT, EAST, WEST, FRONT, BACK
};

vector<int> dice = {0, 0, 0, 0, 0, 0};

void Move(int d)
{
    switch (d)
    {
    case E:
        dice = {dice[WEST], dice[EAST], dice[TOP], dice[BOT], dice[FRONT], dice[BACK]};
        break;
    case W:
        dice = {dice[EAST], dice[WEST], dice[BOT], dice[TOP], dice[FRONT], dice[BACK]};
        break;
    case N:
        dice = {dice[BACK], dice[FRONT], dice[EAST], dice[WEST], dice[TOP], dice[BOT]};
        break;
    case S:
        dice = {dice[FRONT], dice[BACK], dice[EAST], dice[WEST], dice[BOT], dice[TOP]};
        break;

    default:
        break;
    }
}

int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

main()
{
    FASTIO;

    int n, m, x, y, k;
    cin >> n >> m >> y >> x >> k;
    vector<vector<int>> board(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    vector<int> cmd(k);
    for (int i = 0; i < k; i++)
        cin >> cmd[i];

    for (int d : cmd)
    {
        int ny = y + dy[d];
        int nx = x + dx[d];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        
        Move(d);

        if (board[ny][nx] != 0)
        {
            dice[BOT] = board[ny][nx];
            board[ny][nx] = 0;
        }
        else
        {
            board[ny][nx] = dice[BOT];
        }
        cout << dice[TOP] << endl;
        y = ny;
        x = nx;
    }

    return 0;
}