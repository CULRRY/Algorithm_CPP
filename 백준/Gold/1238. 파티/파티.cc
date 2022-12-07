#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 987654321;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<int>> adj(n+1, vector<int>(n+1, INF));

    for (int i = 0; i < m; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;

        adj[s][e] = w;
    }
    for (int i = 1; i <= n; i++) adj[i][i] = 0;

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                adj[i][j] = std::min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        max = std::max(adj[i][x] + adj[x][i], max); 
    }

    cout << max;

    return 0;
}