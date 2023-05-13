#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

struct Point
{
    int y, x;
};

int board[101][101];

Point move(Point now, int d)
{
    switch (d)
    {
    case 0:
        return {now.y, now.x + 1};
    case 1:
        return {now.y - 1, now.x};
    case 2:
        return {now.y, now.x - 1};
    case 3:
        return {now.y + 1, now.x};
    default:
        break;
    }
}

int main()
{
    FASTIO;

    int n;
    cin >> n;



    while (n--)
    {
        int sy, sx, d, g;
        
        cin >> sx >> sy >> d >> g;

        board[sy][sx] = 1;

        vector<int> dir;

        Point now = move({sy, sx}, d);
        board[now.y][now.x] = true;
        dir.push_back(d);

        for (int i = 1; i <= g; i++)
        {
            int sz = dir.size() - 1;
            for (int i = sz; i >= 0; i--)
            {
                now = move(now, (dir[i] + 1) % 4);
                board[now.y][now.x] = true;
                dir.push_back((dir[i] + 1) % 4);
            }
        }        
        
    }
    
    int ans = 0;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (board[i][j] == 0)
                continue;
            if (board[i][j+1] == 0)
                continue;
            if (board[i+1][j] == 0)
                continue;
            if (board[i+1][j+1] == 0)
                continue;
            
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}