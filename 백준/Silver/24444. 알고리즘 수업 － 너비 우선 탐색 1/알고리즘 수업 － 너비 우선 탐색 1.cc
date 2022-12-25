#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    FASTIO;

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> adj(n+1, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<bool> discoverd(n+1, false);

    queue<int> q;
    q.push(r);
    discoverd[r] = true;

    vector<int> que(n+1, 0);
    int cnt = 1;

    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        que[now] = cnt++;

        for (int next : adj[now])
        {
            if (discoverd[next])
                continue;
            
            q.push(next);
            discoverd[next] = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << que[i] << "\n";
    }

    return 0;
}