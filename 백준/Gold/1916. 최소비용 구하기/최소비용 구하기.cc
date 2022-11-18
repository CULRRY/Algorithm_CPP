#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph;
    graph.assign(N+1, vector<int>(N+1, -1));

    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;

        if (from == to)
        {
            graph[from][to] = 0;
            continue;
        }
        if (graph[from][to] == -1)
            graph[from][to] = cost;
        else
        {
            if (graph[from][to] > cost)
                graph[from][to] = cost;
        }
    }
    vector<int> cost(N + 1, 987654321);
    int from, to;
    cin >> from >> to;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, from));
    cost[from] = 0;

    while (!pq.empty())
    {
        int now = pq.top().second;
        int nowCost = pq.top().first;
        pq.pop();

        if (nowCost > cost[now])
            continue;

        for (int i = 1; i <= N; i++)
        {
            int next = graph[now][i];
            if (next != -1)
            {
                int nextCost = cost[now] + next;
                if (nextCost < cost[i])
                {
                    cost[i] = nextCost;
                    pq.push(make_pair(cost[i], i));
                }
            }
        }

    }

    cout << cost[to];
    

    return 0;
}