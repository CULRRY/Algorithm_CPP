#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

struct CCTV
{
    int y, x;
    int n;
    vector<int> light;
};

enum
{
    N, E, S, W,
};

int n, m;
vector<vector<char>> board;
vector<CCTV> camera;
int ans = INT_MAX;

void RotateRight(CCTV& cctv)
{
    for (int i = 0; i < cctv.light.size(); i++)
    {
        cctv.light[i]++;
        cctv.light[i] %= 4;
    }
}

void RotateLeft(CCTV& cctv)
{
    for (int i = 0; i < cctv.light.size(); i++)
    {
        if (cctv.light[i] == N)
            cctv.light[i] = W;
        else
            cctv.light[i]--;
    }
}

void LightUp(CCTV& cctv, vector<vector<char>>& board)
{
    for (int d : cctv.light)
    {
        switch (d)
        {
        case N:
            for (int i = cctv.y - 1; i >= 0; i--)
            {
                if (board[i][cctv.x] == '6')
                    break;
                board[i][cctv.x] = '#';
            }        
            break;
        case E:
            for (int i = cctv.x + 1; i < m; i++)
            {
                if (board[cctv.y][i] == '6')
                    break;
                board[cctv.y][i] = '#';
            }
            break;
        case S:
            for (int i = cctv.y + 1; i < n; i++)
            {
                if (board[i][cctv.x] == '6')
                    break;
                board[i][cctv.x] = '#';
            }
            break;
        case W:
            for (int i = cctv.x - 1; i >= 0; i--)
            {
                if (board[cctv.y][i] == '6')
                    break;
                board[cctv.y][i] = '#';
            }
            break;
        default:
            break;
        }
    }
}

int Calculate()
{  
    vector<vector<char>> tmp = board;
    for (CCTV cctv : camera)
    {
        LightUp(cctv, tmp);
    }
    int result = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(tmp[i][j] == '0')
                result++;
        }
    }

    return result;
}


void bt(int depth)
{
    if (depth == camera.size())
    {
        ans = std::min(Calculate(), ans);
        return;
    }

    if (camera[depth].n == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            RotateRight(camera[depth]);
            bt(depth + 1);
        }
    }
    else if (camera[depth].n == 5)
    {
        bt(depth + 1);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            RotateRight(camera[depth]);
            bt(depth + 1);
        }
    }
}

int main()
{
    FASTIO;

    cin >> n >> m;
    board = vector<vector<char>>(n, vector<char>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int tile;
            cin >> tile;
            if (tile == 0 || tile == 6)
                board[i][j] = '0' + tile;
            else
            {
                board[i][j] = '#';
                CCTV cctv;
                cctv.y = i;
                cctv.x = j;
                cctv.n = tile;
                switch (tile)
                {
                case 1:
                    cctv.light = {N};
                    break;
                case 2:
                    cctv.light = {N, S};
                    break;
                case 3:
                    cctv.light = {N, E};
                    break;
                case 4:
                    cctv.light = {N, E, S};
                    break;
                case 5:
                    cctv.light = {N, E, S, W};
                    break;
                default:
                    break;
                }

                camera.push_back(cctv);
            }
        }
    }

    bt(0);

    cout << ans << endl;

    return 0;
}