#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

vector<int> parent;
vector<int> trace;
vector<int> visited;
vector<bool> finished;
int cnt = 1;
bool findCycle = false;
int n;
int Find(int p)
{
    if (p == parent[p])
        return p;
    
    return parent[p] = Find(parent[p]);
}

void Union(int p, int q)
{
    p = Find(p);
    q = Find(q);

    parent[q] = p;
}

bool Equal(int p, int q)
{
    return Find(p) == Find(q);
}

void Trace(int now, int dest)
{
    findCycle = true;
    while (true)
    {
        if (now == dest)
        {
            break;
        }
        Union(now, trace[now]);
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
            for (int next : adj[now])
            {
                if (discoverd[next] == true)
                    continue;
                if (Find(now) == Find(next))
                {
                    cout << cnt << " ";
                    return;
                }

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
    parent = vector<int>(n+1);
    trace = vector<int>(n+1, -1);
    visited = vector<int>(n+1, -1);
    finished = vector<bool>(n+1, false);
    std::iota(parent.begin(), parent.end(), 0);


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