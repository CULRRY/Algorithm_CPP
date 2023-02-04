#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

enum 
{
    N, E, S, W
};

vector<int> dy = {-1, 0, 1, 0};
vector<int> dx = {0, 1, 0, -1};

int Rotate(int d)
{
    if (d == N)
        return W;
    
    return d-1;
}

int main()
{
    FASTIO;

    int n, m;
    int y, x, d;
    cin >> n >> m;
    cin >> y >> x >> d;
    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    int ans = 1;
    board[y][x] = 2;
    while (true)
    {
        int ny, nx, nd = d;
        bool rotateFlag = false;
        for (int i = 0; i < 4; i++)
        {
            nd = Rotate(nd);
            ny = y + dy[nd];
            nx = x + dx[nd];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (board[ny][nx] == 1)
                continue;
            if (board[ny][nx] == 2)
                continue;

            rotateFlag = true;   
            d = nd;
            y = ny;
            x = nx;
            board[y][x] = 2;
            ans++;
            break;
        }
        if (!rotateFlag)
        {
            ny = y - dy[d];
            nx = x - dx[d];
            if (board[ny][nx] == 1)
                break;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                break;
            y = ny;
            x = nx;
        }
    }
    

    cout << ans;

    return 0;
}