#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 987654321;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        if (adj[s][e] > w)
        {
            adj[s][e] = w;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        adj[i][i] = 0;
    }
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adj[i][j] >= INF)
                cout << 0 << " ";
            else
                cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}