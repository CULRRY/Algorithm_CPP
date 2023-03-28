#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n;
enum
{
    EARLY, COMMON
};

vector<vector<int>> adj;
vector<vector<int>> dp;
vector<bool> visited;
int ans = 0;

void dfs(int now)
{
    visited[now] = true;
    dp[now][EARLY] = 1;
    for (int child : adj[now])
    {
        if (visited[child] == true)
            continue;
        
        dfs(child);

        dp[now][COMMON] += dp[child][EARLY];
        dp[now][EARLY] += std::min(dp[child][COMMON], dp[child][EARLY]);
    } 
}


int main()
{
    FASTIO;

    cin >> n;
    adj.reserve(n + 1);
    dp.assign(n+1, vector<int>(2, 0));
    visited.assign(n+1, false);
    for (int i = 1; i <= n; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    dfs(1);

    cout << std::min(dp[1][EARLY], dp[1][COMMON]);

    return 0;
}