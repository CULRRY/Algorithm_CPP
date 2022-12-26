#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;
vector<int> visited;
vector<bool> finished;
int cnt;
int group;
void DFS(vector<vector<int>>& adj, int s)
{
    int now = s;
    visited[now] = cnt++;

    for (int next : adj[now])
    {
        if (!visited[next])\
        {
            DFS(adj, next);
        }
        else
        {
            if(!finished[next])
            {
                group += visited[now] - visited[next] + 1;
            }
        }
    }
    
    finished[now] = true;
}




int main()
{
    FASTIO;

    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1, vector<int>());
        visited.assign(n+1, 0);
        finished.assign(n+1, false);
        cnt = 1; group = 0;

        for (int i = 1; i <= n; i++)
        {
            int d;
            cin >> d;
            adj[i].push_back(d);
        }

        for (int i = 1; i <= n; i++)
        {
            if(!finished[i])
                DFS(adj, i);
        }

        cout << n - group << "\n";

    }

    return 0;
}