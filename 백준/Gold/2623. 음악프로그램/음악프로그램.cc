#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int n, m;

int main()
{
    FASTIO;


    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    vector<int> inDegree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int k, s, e;
        cin >> k >> s;
        for (int j = 0; j < k - 1; j++)
        {
            cin >> e;
            if (adj[s][e] == 0)
            {
                adj[s][e] = 1;
                inDegree[e]++;
            }
            s = e;
        }
    }


    queue<int> q;
    vector<int> result;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        result.push_back(now);

        for (int j = 1; j <= n; j++)
        {
            if (adj[now][j] == 1)
            {
                if (--inDegree[j] == 0)
                {
                    q.push(j);
                }
            }
        }
    }

    if (result.size() != n)
    {   
        cout << 0;
        return 0;
    }
    for (int i : result)
    {
        cout << i << "\n";
    }

    return 0;
}