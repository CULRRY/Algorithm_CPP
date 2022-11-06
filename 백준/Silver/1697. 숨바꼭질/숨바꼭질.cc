#include <bits/stdc++.h>
using namespace std;
int bfs(vector<vector<int>> &graph, int s, int t)
{
    if (s == t)
        return 0;
    queue<int> q;
    q.push(s);
    vector<bool> discoverd;
    discoverd.assign(100001, 0);
    discoverd[s] = true;
    int count = 0;
    while (!q.empty())
    {
        int sz = q.size();
        count++;
        for (int j = 0; j < sz; j++)
        {
            int now = q.front();
            q.pop();
            for (int i = 0; i < graph[now].size(); i++)
            {
                if (graph[now][i] == t)
                {
                    return count++;
                }
                if (!discoverd[graph[now][i]])
                {
                    q.push(graph[now][i]);
                    discoverd[graph[now][i]] = true;
                }
            }
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<vector<int>> graph;
    graph.assign(100001, vector<int>());

    graph[0].push_back(1);
    for (int i = 1; i <= 100000; i++)
    {
        if (i + 1 <= 100000)
            graph[i].push_back(i + 1);
        if (i - 1 <= 100000)
            graph[i].push_back(i - 1);
        if (i * 2 <= 100000)
            graph[i].push_back(i * 2);
    }

    cout << bfs(graph, N, K);

    return 0;
}