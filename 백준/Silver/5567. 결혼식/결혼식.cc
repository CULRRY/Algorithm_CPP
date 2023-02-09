#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;


int main()
{
    FASTIO;
    int ans = 0;
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1, vector<int>());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    queue<int> q;
    vector<bool> discovered(n+1, false);
    q.push(1);
    discovered[1] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        if (cnt == 2)
            break;
        for (int i = 0; i < sz; i++)
        {
            int now = q.front();
            q.pop();
            for (int next : adj[now])
            {
                if (discovered[next] == true)
                    continue;
                
                discovered[next] = true;
                ans++;
                q.push(next);
            }
        }
        cnt++;

    }
    cout << ans << endl;
    return 0;
}