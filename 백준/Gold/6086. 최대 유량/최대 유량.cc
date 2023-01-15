#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
vector<vector<int>> adj(52, vector<int>());
vector<vector<int>> c(52, vector<int>(52, 0)); // 용량
vector<vector<int>> f(52, vector<int>(52, 0)); // 유량
int idx(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'A' - 6;

    return c - 'A';
}

int main()
{
    FASTIO;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char c1, c2;
        int w;
        cin >> c1 >> c2 >> w;
        int v1 = idx(c1);
        int v2 = idx(c2);

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        c[v1][v2] += w;
        c[v2][v1] += w;
    }

    int start = idx('A');
    int dest  = idx('Z');
    int ans = 0;
    while (true)
    {
        vector<int> p(52, -1);
        queue<int> q;
        q.push(start);

        while (!q.empty())
        {
            int now = q.front();
            q.pop();

            if (now == dest)
                break;
            
            for (int next : adj[now])
            {
                if (p[next] != -1)
                    continue;
                if (c[now][next] - f[now][next] <= 0)
                    continue;
                
                q.push(next);
                p[next] = now;
            }
        }

        if (p[dest] == -1)
            break;
        
        int min = INT_MAX;
        for (int i = dest; i != start; i = p[i])
            min = std::min(min, c[p[i]][i] - f[p[i]][i]);

        for (int i = dest; i != start; i = p[i])
        {
            f[p[i]][i] += min;
            f[i][p[i]] -= min;
        }

        ans += min;
        
    }
    
    cout << ans << endl;

    

    return 0;
}