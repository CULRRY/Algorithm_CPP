#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
using ull = unsigned long long;
int n, m, r;
vector<vector<int>> adj;
vector<int> visited;
ull answer = 0;
int cnt = 1;
void dfs(int now, int depth)
{
    visited[now] = cnt++;
    answer += (ull)depth * (ull)visited[now];

    for (int next : adj[now])
    {
        if (visited[next] != -1)
            continue;
        
        dfs(next, depth + 1);
    }
}

int main()
{
    FASTIO;

    cin >> n >> m >> r;
    adj.resize(n+1);
    visited.assign(n+1, -1);

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

    dfs(r, 0);

    cout << answer;

    return 0;
}