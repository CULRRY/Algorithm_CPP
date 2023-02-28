#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n, m, r;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> ans;
int cnt = 1;
void dfs(int now)
{
    visited[now] = true;
    ans[now] = cnt++;
    for (int i : adj[now])
    {
        if (visited[i] == true)
            continue;
        
        dfs(i);
    }
}


int main()
{
    FASTIO;
    
    cin >> n >> m >> r;
    adj = vector<vector<int>>(n+1);
    visited = vector<bool>(n+1, false);
    ans = vector<int>(n+1, 0);

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }

    dfs(r);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}