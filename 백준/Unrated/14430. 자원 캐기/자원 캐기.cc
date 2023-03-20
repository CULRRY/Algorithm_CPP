#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n, m;
vector<vector<int>> board;
int ans = 0;
enum
{
    R, D
};

int dy[] = {0, 1};
int dx[] = {1, 0};

bool IsBound(int y, int x)
{
    if (y < 0 || y >= n || x < 0 || x >= m)
        return false;
    else
        return true;
}

int main()
{
    FASTIO;

    cin >> n >> m;
    board = vector<vector<int>>(n, vector<int>(m, 0));
    int dp[n][m];
    
    for (auto& v : board)
    {
        for (int& i : v)
        {
            cin >> i;
        }
    }

    dp[0][0] = board[0][0];

    for (int i = 1; i < n; i++)
    {
        int y = i; 
        int x = 0;
        while (IsBound(y, x))
        {
            int prevMax = 0;
            int prevY = y - 1;
            int prevX = x;
            if (IsBound(prevY, prevX))
                prevMax = std::max(prevMax, dp[prevY][prevX]);
            
            prevY = y;
            prevX = x - 1;
            if (IsBound(prevY, prevX))
                prevMax = std::max(prevMax, dp[prevY][prevX]);

            dp[y][x] = prevMax + board[y][x];
            y -= 1;
            x += 1;
        }
        
    }
    for (int i = 1; i < m; i++)
    {
        int y = n-1;
        int x = i;
        while (IsBound(y, x))
        {
            int prevMax = 0;
            int prevY = y - 1;
            int prevX = x;
            if (IsBound(prevY, prevX))
                prevMax = std::max(prevMax, dp[prevY][prevX]);

            prevY = y;
            prevX = x - 1;
            if (IsBound(prevY, prevX))
                prevMax = std::max(prevMax, dp[prevY][prevX]);

            dp[y][x] = prevMax + board[y][x];
            y -= 1;
            x += 1;
        }
    }

    cout << dp[n-1][m-1];

    return 0;
}