#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1000000;
struct node
{
    int n, weight;
};

int v, e;
vector<int> cost;
vector<vector<node>> adj;


void Dijikstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    cost[start] = 0;

    while (!pq.empty())
    {
        int nowCost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (nowCost > cost[now])
            continue;

        for (int next = 0; next < adj[now].size(); next++)
        {
                int nextCost = cost[now] + adj[now][next].weight;
                if (cost[adj[now][next].n] > nextCost)
                {
                    cost[adj[now][next].n] = nextCost;
                    pq.push(make_pair(-cost[adj[now][next].n], adj[now][next].n));
                }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;

    int from;
    cin >> from;
    adj.assign(v + 1, vector<node>());
    cost.assign(v + 1, INF);


    for (int i = 0; i < e; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        int idx = -1;
        for (int j = 0; j < adj[start].size(); j++)
        {
            if (adj[start][j].n == end)
            {
                idx = j;
                break;
            }
        }

        if (idx = -1)
        {
            adj[start].push_back({end, weight});
        }
        else
        {
            if (adj[start][idx].weight > weight)
                adj[start][idx].weight = weight;
        }

        
    }

    Dijikstra(from);

    for (int i = 1; i <= v; i++)
    {
        int out = cost[i];
        if (out >= INF || out < 0)
        {
            cout << "INF" << "\n";
        }
        else
        {
            cout << out << "\n";
        }
    }

    return 0;
}