#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;
int n, m;
vector<int> cost;


void BFS(vector<vector<int>>& adj, int start)
{
    vector<bool> discoverd(n+1, false);
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int next : adj[now])
        {
            if (discoverd[next])
                continue;
            
            cost[next] += cost[now];
            q.push(next);
            discoverd[next] = true;
        }
    }
    
}

int main()
{
    FASTIO;


    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>());
    cost = vector<int>(n+1);

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a == -1)
            continue;

        adj[a].push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        int a, w;
        cin >> a >> w;
        cost[a] += w;
    }

    BFS(adj, 1);

    for (int i = 1; i <= n; i++)
    {
        cout << cost[i] << " ";
    }


    

    return 0;
}