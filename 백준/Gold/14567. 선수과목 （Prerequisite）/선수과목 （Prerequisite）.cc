#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1, vector<int>());
    vector<int> inDegree(n+1, 0);
    queue<int> q;
    vector<int> ans(n+1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        inDegree[b]++;
    }

    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            ans[i] = cnt;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int sz = q.size();
        cnt++;
        while (sz--)
        {   
            int now = q.front();
            q.pop();

            for (int next : adj[now])
            {
                if (--inDegree[next] == 0)
                {
                    q.push(next);
                    ans[next] = cnt;
                }
            }
        }
        
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }


    return 0;
}