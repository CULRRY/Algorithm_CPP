#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> v(n + 1, vector<int>(m + 1, 0));

    int wy;
    int wx;
    if (k == 0)
    {
        wy = 1;
        wx = 1;
    }
    else
    {
        wy = (k - 1) / m + 1;
        wx = (k - 1) % m + 1;
    }

    v[1][1] = 1;

    for (int i = 1; i <= wy; i++)
    {
        for (int j = 1; j <= wx; j++)
        {
            if (i == 1 && j == 1)
                continue;
            v[i][j] = v[i][j-1] + v[i-1][j];
        }
    }
    for (int i = wy; i <= n; i++)
    {
        for (int j = wx; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;
            v[i][j] = v[i][j - 1] + v[i - 1][j];
        }
    }

    cout << v[n][m];

    return 0;
}