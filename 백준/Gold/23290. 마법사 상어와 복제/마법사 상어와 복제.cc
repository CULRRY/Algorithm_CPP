#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int m, s;
vector<vector<vector<int>>> board(5, vector<vector<int>>(5));
vector<vector<int>> smell(5, vector<int>(5, 0));
int sy, sx;

struct Point
{
    int y, x;
};

int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

int sdy[] = {-1, 0, 1, 0};
int sdx[] = {0, -1, 0, 1};

int mcnt = -1;
vector<Point> seq(3);
vector<Point> mseq(3);
void bt(int depth, int cnt, int y, int x, vector<vector<vector<int>>>& tmp)
{

    if (depth == 3)
    {
        if (cnt > mcnt)
        {
            sy = y;
            sx = x;
            for (int i = 0; i < 3; i++)
            {
                mseq[i] = seq[i];
            }
            mcnt = cnt;
        }
        return;
    }

    for (int d = 0; d < 4; d++)
    {
        int ny = y + sdy[d];
        int nx = x + sdx[d];
        if (ny <= 0 || ny > 4 || nx <= 0 || nx > 4)
            continue;

        cnt += tmp[ny][nx].size();
        seq[depth] = {ny, nx};
        vector<int> backup = tmp[ny][nx];
        tmp[ny][nx].clear();
        bt(depth + 1, cnt, ny, nx, tmp);
        tmp[ny][nx] = backup;
        cnt -= tmp[ny][nx].size();
    }

}

void magic()
{
    vector<vector<vector<int>>> tmp(5, vector<vector<int>>(5));
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (board[i][j].empty())
                continue;
            for (int d : board[i][j])
            {
                int flag = false;
                for (int k = 0; k < 8; k++)
                {
                    int nd;
                    if (d >= k + 1)
                        nd = d - k;
                    else
                        nd = 8 + d - k;

                    int ny = i + dy[nd];
                    int nx = j + dx[nd];

                    if (ny <= 0 || ny > 4 || nx <= 0 || nx > 4)
                        continue;
                    if (smell[ny][nx] != 0)
                        continue;
                    if (ny == sy && nx == sx)
                        continue;
                    
                    tmp[ny][nx].push_back(nd);
                    flag = true;
                    break;
                }
                if (flag == false)
                    tmp[i][j].push_back(d);
            }
            
        }
    }
    seq = vector<Point>(3);
    mseq = vector<Point>(3);
    mcnt = -1;
    bt(0, 0, sy, sx, tmp);

    for (Point p : mseq)
    {
        if (tmp[p.y][p.x].empty())
            continue;
        tmp[p.y][p.x].clear();
        smell[p.y][p.x] = 3;
    }

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (smell[i][j] != 0)
                smell[i][j]--;
        }
    }

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (tmp[i][j].empty())
                continue;
            
            for (int d : tmp[i][j])
                board[i][j].push_back(d);
        }
    }
}

int main()
{
    FASTIO;

    cin >> m >> s;

    while (m--)
    {
        int y, x, d;
        cin >> y >> x >> d;
        board[y][x].push_back(d);
    }
    cin >> sy >> sx;

    while (s--)
    {
        magic();
    }
    
    int ans = 0;

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            ans += board[i][j].size();
        }
    }

    cout << ans;
    return 0;
}