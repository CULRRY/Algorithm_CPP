#include <bits/stdc++.h>
using namespace std;
int N;

void bfs(vector<vector<int>> &graph)
{
    vector<bool> discoverd(N + 1, 0);
    vector<int> parent(N + 1, 0);
    queue<int> q;
    q.push(1);
    discoverd[1] = true;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if (!discoverd[next])
            {
                q.push(next);
                parent[next] = now;
                discoverd[next] = true;
            }
        }
    }

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        int x1, x2;
        cin >> x1 >> x2;
        graph[x1].push_back(x2);
        graph[x2].push_back(x1);
    }

    bfs(graph);

    return 0;
}
