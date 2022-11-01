#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> visited;
int N;
int count = 0;

void dfs(int v)
{
    visited[v] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (graph[v][i] && !visited[i])
        {
            ::count++;
            dfs(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    graph.assign(N + 1, vector<int>(N + 1, 0));
    visited.assign(N + 1, 0);
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int num, adj;
        cin >> num >> adj;
        graph[num][adj] = 1;
        graph[adj][num] = 1;
    }
   
    dfs(1);

    cout << ::count;

    return 0;
}