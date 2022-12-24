#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int n, m;
vector<bool> visited;
vector<bool> finished;

bool isCycle = false;

void dfs(vector<vector<int>>& adj, int idx)
{
    visited[idx] = true;

    for (int i = 1; i <= n; i++)
    {
        if (adj[idx][i] == 0)
            continue;

        if (visited[i])
        {
            if(!finished[i])
            {
                isCycle = true;
            }

            continue;
        }
        
        dfs(adj, i);
    }

    finished[idx] = true;
}


int main()
{
    FASTIO;


    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    vector<int> inDegree(n + 1, 0);
    finished.assign(n+1, false);
    visited.assign(n+1, false);

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

    for (int i = 1; i <= n; i++)
    {
        if (!finished[i])
            dfs(adj, i);
    }

    if (isCycle)
    {
        cout << 0;
        return 0;
    }

    queue<int> q;
    vector<int> result(n);
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        int now = q.front();
        q.pop();
        result[i] = now;

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

    for (int i : result)
    {
        cout << i << "\n";
    }

    return 0;
}