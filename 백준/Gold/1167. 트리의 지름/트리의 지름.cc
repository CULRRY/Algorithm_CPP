#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int dest, weight;
};

using vve = vector<vector<Edge>>;
vve adj;
vector<bool> visited;
int maxL = 0;
int maxNode = 0;
void DFS(int start, int accum)
{
    int now = start;
    visited[now] = true;

    if (accum > maxL)
    {
        maxL = accum;
        maxNode = now;
    }

    for (int i = 0; i < adj[now].size(); i++)
    {
        int next = adj[now][i].dest;
        if (visited[next])
            continue;

        DFS(next, accum + adj[now][i].weight);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v;
    cin >> v;

    adj.assign(v + 1, vector<Edge>());

    for (int i = 0; i < v; i++)
    {
        int start;
        cin >> start;
        while (true)
        {
            int dest, weight;
            cin >> dest;
            if (dest == -1)
                break;

            cin >> weight;

            adj[start].push_back({dest, weight});
        }
    }

    visited.assign(v + 1, false);
    DFS(1, 0);
    visited.assign(v + 1, false);
    DFS(maxNode, 0);

    cout << maxL << "\n";

    return 0;
}