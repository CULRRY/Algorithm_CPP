#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 987654321;

int n, e;
void Dijikstra(const vector<vector<int>>& graph, vector<int>& cost, int start)
{
    cost = vector<int>(n + 1, INF);
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    cost[start] = 0;

    while (!pq.empty())
    {
        int now = pq.top().second;
        int nowCost = -pq.top().first;
        pq.pop();

        if (nowCost > cost[now])
            continue;
        
        for (int next = 1; next <= n; next++)
        {
            if (graph[now][next] != -1)
            {
                cost[next] = ::min(cost[next], cost[now] + graph[now][next]);
                if (cost[next] == cost[now] + graph[now][next])
                {
                    pq.push(make_pair(-cost[next], next));
                }
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;
    vector<vector<int>> graph(n+1, vector<int>(n+1, -1));
    for (int i = 0; i < e; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from][to] = weight;
        graph[to][from] = weight;
    }

    int via1, via2;
    cin >> via1 >> via2;

    int answer = 0;
    vector<int> costFrom;

    Dijikstra(graph, costFrom, 1);

    int route1 = costFrom[via1];
    int route2 = costFrom[via2];

    Dijikstra(graph, costFrom, via1);
    route1 += costFrom[via2];
    route2 += costFrom[n] + costFrom[via2];
    
    Dijikstra(graph, costFrom, via2);
    route1 += costFrom[n];

    answer = ::min(route1, route2);
    
    if (answer >= INF || answer < 0)
        answer = -1;

    cout << answer << "\n";
    return 0;
}