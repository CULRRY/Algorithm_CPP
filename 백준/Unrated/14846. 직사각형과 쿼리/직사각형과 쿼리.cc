#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int dp[301][301][11];
int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<vector<int>> matrix(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int q;
    cin >> q;
 

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= 10; k++)
            {
                dp[i][j][k] = dp[i][j-1][k] + dp[i-1][j][k] - dp[i-1][j-1][k];
            }

            dp[i][j][matrix[i][j]]++;
        }
    }
    while (q--)   
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int cnt = 0;
        int tmp[11] = {0, };
        for (int i = 1; i <= 10; i++)
        {
            tmp[i] = dp[x2][y2][i];
        }

        for (int i = 1; i <= 10; i++)
        {
            tmp[i] -= dp[x1 - 1][y2][i];
            tmp[i] -= dp[x2][y1 - 1][i];
            tmp[i] += dp[x1 - 1][y1 - 1][i];
        }

        for (int i : tmp)
        {
            if (i > 0)
                cnt++;
        }

        cout << cnt << endl;
    }
    
    

    return 0;
}