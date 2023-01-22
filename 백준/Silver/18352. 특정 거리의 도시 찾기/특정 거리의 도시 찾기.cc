#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
vector<int> ans;
int n, m, k, x;
void bfs(vector<vector<int>>& adj, int start)
{
    vector<int> discovered(adj.size(), 0);
    queue<int> q;
    q.push(start);
    discovered[start] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();

        for (int i = 0; i < sz; i++)
        {
            int now = q.front();
            q.pop();
            if (cnt == k)
            {
                ans.push_back(now);
                continue;
            }

            for (int& next : adj[now])
            {
                if (discovered[next] == true)
                    continue;
                
                q.push(next);
                discovered[next] = true;
            }
        }
        if (cnt == k)
        {
            return;
        }
        cnt++;
    }
    
}

int main()
{
    FASTIO;

    cin >> n >> m >> k >> x;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
    }
    bfs(adj, x);
    if (ans.empty())
    {
        cout << -1;
        return 0;
    }

    sort(ans.begin(), ans.end());

    for (int i : ans)
    {
        cout << i << endl;
    }


    return 0;
}