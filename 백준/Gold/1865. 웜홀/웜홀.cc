#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 9876543;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, w;
        cin >> n >> m >> w;
        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());
        vector<int> dist(n + 1, INF);

        for (int i = 0; i < m; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            adj[s].push_back(make_pair(e, t));
            adj[e].push_back(make_pair(s, t));
        }

        for (int i = 0; i < w; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;

            adj[s].push_back(make_pair(e, -t));
        }
        bool minus = false;
        dist[1] = 0;
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                for (int l = 0; l < adj[k].size(); l++)
                {
                    if (dist[adj[k][l].first] > dist[k] + adj[k][l].second)
                    {
                        dist[adj[k][l].first] = dist[k] + adj[k][l].second;

                        if (j == n)
                            minus = true;
                    }
                }
            }
        }

        if (minus)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }

    return 0;
}