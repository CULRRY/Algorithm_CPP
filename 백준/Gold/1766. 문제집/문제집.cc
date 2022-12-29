#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1, vector<int>());
    vector<int> inDegree(n+1, 0);
    priority_queue<int, vector<int>, greater<int>> q;

    vector<int> result(n);

    for (int i = 1; i <= m; i++)
    {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
        inDegree[e]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int now = q.top();
        q.pop();
        result[i] = now;
        for (int next : adj[now])
        {
            if (--inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    

    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}