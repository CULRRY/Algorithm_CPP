#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;
int n, m;
vector<vector<int>> adj;
vector<int> result;

void bfs(int start)
{
    queue<int> q;
    vector<bool> discoverd(n + 1, false);
    q.push(start);
    discoverd[start] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            int now = q.front();
            q.pop();

            result[now] = cnt;
            
            for (int next = 1; next <= n; next++)
            {
                if (adj[now][next] == 0)
                    continue;
                if (discoverd[next] == true)
                    continue;

                q.push(next);
                discoverd[next] = true;
            }
        }
        cnt++;
    }

}

int main()
{
    FASTIO;

    cin >> n >> m;

    adj = vector<vector<int>>(n+1, vector<int>(n+1, 0));


    for (int i = 0; i < m; i++)
    {
        int v1,v2;
        cin >> v1 >> v2;
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int query;
        cin >> query;
        result = vector<int>(n + 1, -1);
        if (query == 1)
        {
            int v1, v2;
            cin >> v1 >> v2;
            adj[v1][v2] = 1;
            adj[v2][v1] = 1;
        }
        else
        {
            int v1, v2;
            cin >> v1 >> v2;
            adj[v1][v2] = 0;
            adj[v2][v1] = 0;
        }

        bfs(1);

        for (int i = 1; i <= n; i++)
        {
            cout << result[i] << " ";
        }

        cout << endl;
    }
    
    

    return 0;
}