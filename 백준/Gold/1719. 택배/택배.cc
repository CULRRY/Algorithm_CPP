#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 10001));

    for (int i = 0; i < m; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;

        adj[v1][v2] = w;
        adj[v2][v1] = w;
    }
    for (int i = 1; i <= n; i++)
        adj[i][i] = 0;


    vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            if (adj[i][j] != 10001)
                ans[i][j] = j;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    ans[i][j] = ans[i][k];
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ans[i][j] == 0)
                cout << "-"
                     << " ";
            else
                cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}