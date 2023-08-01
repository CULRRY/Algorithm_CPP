#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> w;
vector<int> inDegree;
vector<int> outDegree;


int main()
{
    FASTIO;


    cin >> n >> m;
    adj = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    w = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    inDegree = vector<int>(n + 1, 0);
    outDegree = vector<int>(n + 1, 0);
    while (m--)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1][v2] = w;
        inDegree[v2]++;
        outDegree[v1]++;
    }
    queue<int> q;
    vector<int> basic;
    for (int i = 1; i <= n; i++)
    {
        if (outDegree[i] == 0)
            basic.push_back(i);
        if (inDegree[i] == 0)
        {
            q.push(i);
            w[i][i] = 1;
        }
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int next = 1; next <= n; next++)
        {
            if (adj[now][next] == 0)
                continue;
            for (int i = 1; i <= n; i++)
            {
                w[i][next] += w[i][now] * adj[now][next];
            }

            if (--inDegree[next] == 0)
                q.push(next);
        }
    }
    
    for (int i : basic)
    {
        cout << i << " " << w[n][i] << endl;
    }

    return 0;
}