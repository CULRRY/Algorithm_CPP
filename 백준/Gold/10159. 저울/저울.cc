#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

vector<bool> visited;
vector<vector<int>> adj;
vector<int> ans;
int cnt = 0;
void dfs(int now)
{
    cnt++;
    visited[now] = true;
    for (int next : adj[now])
    {
        if (visited[next] == true)
            continue;
        
        ans[next]--;
        dfs(next);
    }
}

int main()
{
    FASTIO;

    int n;
    cin >> n;
    adj = vector<vector<int>>(n+1, vector<int>());
    ans = vector<int>(n+1, n);
    int m;
    cin >> m;
    while (m--)
    {
        int b, s;
        cin >> b >> s;
        adj[s].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        visited = vector<bool>(n+1, false);
        cnt = 0;
        dfs(i);
        ans[i] -= cnt;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }


    return 0;
}