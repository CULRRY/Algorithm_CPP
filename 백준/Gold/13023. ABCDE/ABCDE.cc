#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int n, m;
vector<vector<int>> adj;
int ans = 0;
void bt(int depth, vector<bool>& visited, int now, int cnt)
{
    visited[now] = true;
    if (depth > 5)
        return;
    if (cnt == 5)
    {
        ans = 1;
        return;
    }

    for (int next : adj[now])
    {
        if (visited[next] == true)
            continue;
        
        bt(depth + 1, visited, next, cnt+1);
    }
    visited[now] = false;
}

int main()
{
    FASTIO;

    cin >> n >> m;
    adj = vector<vector<int>>(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(n, false);
        bt(1, visited, i, 1);
    }

    cout << ans;

    return 0;
}