#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

struct FireBall
{
    int m, s, d;
};
using Board = vector<vector<vector<FireBall>>>;

int N, M, K;
Board board;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool isBound(int y, int x)
{
    if (x <= 0 || x > N || y <= 0 || y > N)
        return false;

    return true;
}

void Move(FireBall &f, int y, int x, Board &board)
{
    int ny = y, nx = x;
    for (int i = 0; i < f.s; i++)
    {
        ny = ny + dy[f.d];
        nx = nx + dx[f.d];
        if (ny > N)
        {
            ny = 1;
        }
        
        if (ny < 1)
        {
            ny = N;
        }

        if (nx > N)
        {
            nx = 1;
        }
        
        if (nx < 1)
        {
            nx = N;
        }

    }

    board[ny][nx].push_back(f);
}
void Command()
{
    Board tmp(N + 1, vector<vector<FireBall>>(N + 1, vector<FireBall>()));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (board[i][j].empty())
                continue;

            for (FireBall &f : board[i][j])
            {
                Move(f, i, j, tmp);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (tmp[i][j].empty())
                continue;

            if (tmp[i][j].size() >= 2)
            {
                int m = 0, s = 0, d = tmp[i][j][0].d % 2;
                bool flag = true;
                for (FireBall &f : tmp[i][j])
                {
                    m += f.m;
                    s += f.s;
                    if (f.d % 2 != d)
                        flag = false;
                }

                m /= 5;
                s /= tmp[i][j].size();
                tmp[i][j].clear();

                if (m == 0)
                {
                    continue;
                }
                else
                {
                    if (flag)
                    {
                        tmp[i][j].push_back({m, s, 0});
                        tmp[i][j].push_back({m, s, 2});
                        tmp[i][j].push_back({m, s, 4});
                        tmp[i][j].push_back({m, s, 6});
                    }
                    else
                    {
                        tmp[i][j].push_back({m, s, 1});
                        tmp[i][j].push_back({m, s, 3});
                        tmp[i][j].push_back({m, s, 5});
                        tmp[i][j].push_back({m, s, 7});
                    }
                }
            }
        }
    }

    board = tmp;
}



int main()
{
    FASTIO;
    cin >> N >> M >> K;

    board = Board(N + 1, vector<vector<FireBall>>(N + 1, vector<FireBall>()));

    for (int i = 0; i < M; i++)
    {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        board[r][c].push_back({m, s, d});
    }

    for (int i = 0; i < K; i++)
    {
        Command();
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (board[i][j].empty())
                continue;

            for (FireBall &f : board[i][j])
            {
                ans += f.m;
            }
        }
    }

    cout << ans;
    return 0;
}