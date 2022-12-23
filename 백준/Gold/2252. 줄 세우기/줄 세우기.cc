#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;
    vector<int> inDegree(n+1, 0);
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        inDegree[e]++;
    }

    queue<int> q;
    vector<int> result(n);
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }


    for (int i = 0; i < n; i++)
    {
        int now = q.front();
        q.pop();
        result[i] = now;
        for (int node : adj[now])
        {
            inDegree[node]--;
            if (inDegree[node] == 0)
                q.push(node);
        }
    }


    for (int i : result)
    {
        cout << i << " ";
    }


    

    return 0;
}