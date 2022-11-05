#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
void dfs(vector<vector<int>>& g,int s)
{
    visited[s] = true;
    int n = g.size();

    for (int i = 1; i < n; i++)
    {
        if (g[s][i] == 1 && !visited[i])
        {
            dfs(g, i);
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> graph;
    int N, M;
    cin >> N >> M;
    graph.assign(N+1, vector<int>(N+1, 0));
    visited.assign(N+1, 0);
    while (M--)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    int count = 0;
    vector<bool>& v = visited;
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            dfs(graph, i);
            count++;
        }
    }

    cout << count << "\n";


    return 0;
}