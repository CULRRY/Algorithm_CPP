#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int main()
{
    FASTIO;

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> time(n + 1, 0);
        vector<int> inDegree(n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> time[i];

        vector<vector<int>> adj(n + 1, vector<int>());
        for (int i = 0; i < k; i++)
        {
            int s, e;
            cin >> s >> e;

            adj[s].push_back(e);
            inDegree[e]++;
        }
        int w;
        cin >> w;

        queue<int> q;
        vector<int> dp(n + 1, 0);
        int solve = 0;
        int max = 0;
        for (int i = 1; i <= n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (inDegree[w] > 0)
        {

            int x = q.front();
            q.pop();
            for (int j = 0; j < adj[x].size(); j++)
            {
                int next = adj[x][j];
                dp[next] = std::max(dp[next], dp[x] + time[x]);
                inDegree[next]--;
                if (inDegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }

        cout << dp[w] + time[w] << "\n";
    }


    return 0;
}