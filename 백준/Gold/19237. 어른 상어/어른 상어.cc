#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

enum
{
    U = 1, D, L, R
};

int dy[] = {0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, -1, 1};

struct Shark
{
    vector<vector<int>> dirs;
    int d;
    int y, x;
};

struct Smell
{
    int n;
    int t;
};

int n, m, k;
vector<Shark> s;
vector<vector<Smell>> board;


void move()
{
    vector<vector<Smell>> tmp(n, vector<Smell>(n, {0, 0}));
 
    for (int i = 1; i <= m; i++)
    {
        Shark& shark = s[i];

        if (shark.d == -1)
            continue;

        vector<int>& dir = shark.dirs[shark.d];

        bool first = false;

        for (int d : dir)
        {
            int nx = shark.x + dx[d];
            int ny = shark.y + dy[d];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            if (board[ny][nx].n == 0)
            {
                if (tmp[ny][nx].n != 0)
                {
                    if (tmp[ny][nx].n < i)
                    {
                        shark.d = -1;
                    }
                    else
                    {
                        s[tmp[ny][nx].n].d = -1;
                        tmp[ny][nx] = {i, k};
                        shark.y = ny;
                        shark.x = nx;
                        shark.d = d;
                    }
                }
                else
                {
                    tmp[ny][nx] = {i, k};
                    shark.y = ny;
                    shark.x = nx;
                    shark.d = d;
                }

                first = true;
                break;
            }
        }

        if (first)
            continue;

        for (int d : dir)
        {
            int nx = shark.x + dx[d];
            int ny = shark.y + dy[d];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            if (board[ny][nx].n == i)
            {
                tmp[ny][nx] = {i, k};
                shark.y = ny;
                shark.x = nx;
                shark.d = d;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j].t != 0)
            {
                board[i][j].t--;
                if (board[i][j].t == 0)
                    board[i][j].n = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tmp[i][j].n != 0)
            {
                board[i][j] = tmp[i][j];
            }
        }
    }
}

int main()
{
    FASTIO;

    cin >> n >> m >> k;
    board = vector<vector<Smell>>(n, vector<Smell>(n, {0, 0}));
    s = vector<Shark>(m+1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            if (num != 0)
            {
                s[num].y = i;
                s[num].x = j;
                board[i][j] = {num, k};
            }
        }
    }

    for (int i = 1; i <= m; i++)
        cin >> s[i].d;

    for (int i = 1; i <= m; i++)
    {
        s[i].dirs = vector<vector<int>>(5, vector<int>(4));
        for (int r = 1; r <= 4; r++)
        {
            for (int c = 0; c < 4; c++)
            {
                cin >> s[i].dirs[r][c];
            }
        }
    }

    int t = 0;

    while (t <= 1000)
    {
        t++;
        move();


        int condition = 0;

        for (int i = 1; i <= m; i++)
        {
            if (s[i].d != -1)
                condition += i;
        }

        if (condition == 1)
            break;
    }
    
    if (t > 1000)
        t = -1;

    cout << t << endl;

    return 0;
}