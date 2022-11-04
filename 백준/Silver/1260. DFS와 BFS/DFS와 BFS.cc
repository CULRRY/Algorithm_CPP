#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
void DFS(int s)
{
    visited[s] = 1;
    cout << s << " ";
    for (int i = 1; i <= graph[s].size(); i++)
    {
        if (graph[s][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

vector<bool> discoverd;
void BFS(int s)
{
    queue<int> q;
    q.push(s);
    discoverd[s] = 1;
    
    while(!q.empty())
    {
        int now = q.front();
        cout << now << " ";
        q.pop();
        for (int i = 0; i < graph[now].size(); i++)
        {
            if (graph[now][i] == 1 && !discoverd[i])
            {
                q.push(i);
                discoverd[i] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;
    graph.assign(N + 1, vector<int>(N + 1, 0));
    visited.assign(N + 1, 0);
    discoverd.assign(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1][v2] = graph[v2][v1] = 1;
    }
    DFS(V);
    cout << "\n";
    BFS(V);

    return 0;
}