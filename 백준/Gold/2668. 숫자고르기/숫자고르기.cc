#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;
set<int> ans;
void dfs(int start, int now)
{
    visited[now] = true;
    for (int next : adj[now])
    {
        if (next == start)
        {
            int p = now;
            ans.insert(start);
            while (parent[p] != p)
            {
                ans.insert(p);
                p = parent[p];
            }
            return;
        }
        if (visited[next] == true)
            continue;
        parent[next] = now;
        dfs(start, next);
    }
}


int main()
{
    FASTIO;

    int n;
    cin >> n;
    adj = vector<vector<int>>(n+1);
    
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        adj[i].push_back(v);
    }


    for (int i = 1; i <= n; i++)
    {
        parent = vector<int>(n+1, 0);
        visited = vector<bool>(n+1, false);
        parent[i] = i;
        dfs(i, i);
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}