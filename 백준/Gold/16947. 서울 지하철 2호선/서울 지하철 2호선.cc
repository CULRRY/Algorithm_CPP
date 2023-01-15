#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

vector<int> trace;
vector<int> visited;
vector<bool> finished;
vector<bool> cycle;
int cnt = 1;
int n;

void Trace(int now, int dest)
{
    while (true)
    {
        cycle[now] = true;
        if (now == dest)
        {
            break;
        }
        now = trace[now];
    }
}

void dfs(vector<vector<int>>& adj, int now)
{
    visited[now] = cnt++;
    for (int next : adj[now])
    {
        if (visited[next] != -1)
        {
            if (finished[next] == false)
            {
                if (trace[now] == next)
                    continue;

                Trace(now, next);
            }
            continue;
        }

        trace[next] = now;
        dfs(adj, next);
    }
    finished[now] = true;
}

void bfs(vector<vector<int>>& adj, int now)
{
    queue<int> q;
    vector<bool> discoverd(n+1, false);
    discoverd[now] = true;
    q.push(now);
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            now = q.front();
            q.pop();
            if (cycle[now] == true)
            {
                cout << cnt << " ";
                return;
            }
            for (int next : adj[now])
            {
                if (discoverd[next] == true)
                    continue;


                discoverd[next] = true;
                q.push(next);
            }
        }
        cnt++;
    }
    
}

int main()
{
    FASTIO;


    cin >> n;
    vector<vector<int>> adj(n+1, vector<int>());
    cycle = vector<bool>(n+1, false);
    trace = vector<int>(n+1, -1);
    visited = vector<int>(n+1, -1);
    finished = vector<bool>(n+1, false);


    for (int i = 0; i < n; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!finished[i])
            dfs(adj, i);
    }

    for (int i = 1; i <= n; i++)
    {
        bfs(adj, i);
    }

    return 0;
}