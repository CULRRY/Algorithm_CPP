#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int n, weight;
};
vector<vector<Node>> adj;

vector<bool> visited;
int maxLen = 0;
void DFS(int start, int accumWeight)
{
    visited[start] = true;
    if (adj[start].empty())
    {
        if (accumWeight > maxLen)
        {
            maxLen = accumWeight;
        }
    }

    for (int i = 0; i < adj[start].size(); i++)
    {
        if (!visited[adj[start][i].n])
        {
            DFS(adj[start][i].n, accumWeight + adj[start][i].weight);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    adj.assign(n + 1, vector<Node>());
    visited.assign(n + 1, false);

    for (int i = 0; i < n - 1; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        adj[from].push_back({to, weight});
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        int max1 = 0;
        int max2 = 0;
        for (int j = 0; j < adj[i].size(); j++)
        {
            visited.assign(n+1, false);
            visited[i] = true;
            DFS(adj[i][j].n, 0);
            maxLen += adj[i][j].weight;

            if (maxLen >= max1)
            {
                max2 = max1;
                max1 = maxLen;
            }
            else if (maxLen > max2)
            {
                max2 = maxLen;
            }

            maxLen = 0;
        }

        if (max1 + max2 > max)
        {
            max = max1 + max2;
        }
    }

    cout << max << "\n";

    return 0;
}