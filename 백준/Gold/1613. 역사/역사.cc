#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

constexpr int INF = 9876543;

int main()
{
    FASTIO;

    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));

    
    for (int i = 0; i < k; i++)
    {
        int s, e;
        cin >> s >> e;

        adj[s][e] = 1;
    }

    vector<vector<int>> floyd(n+1, vector<int>(n+1, INF));

    for (int i =1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j) floyd[i][j] = 0;
            else if (adj[i][j]) floyd[i][j] = adj[i][j];
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                floyd[i][j] = std::min(floyd[i][j], floyd[i][k] + floyd[k][j]);
            }
        }
    }

    int s;
    cin >> s;
    while (s--)
    {
        int v1, v2;
        cin >> v1 >> v2;

        if (floyd[v1][v2] < INF)
            cout << -1;
        else if (floyd[v2][v1] < INF)
            cout << 1;
        else
            cout << 0;
        
        cout << endl;
    }
    

    return 0;
}