#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
constexpr int INF = 987654321;
using namespace std;
struct Node
{
    int v, w;
};
vector<int> cost;
vector<vector<Node>> adj;
void dijikstra(int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    cost[start] = 0;

    while (!pq.empty())
    {
        int nowCost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (nowCost > cost[now])
            continue;
        
        for (auto next : adj[now])
        {
            int nextCost = cost[now] + next.w;
            if (nextCost < cost[next.v])
            {
                cost[next.v] = nextCost;
                pq.push(make_pair(-cost[next.v], next.v));
            }

        }


    }
    
}

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;
    cost = vector<int> (n+1, INF);
    adj = vector<vector<Node>>(n+1, vector<Node>());


    for (int i = 0; i < m; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back({v2, w});
        adj[v2].push_back({v1, w});
    }

    dijikstra(1);

    cout << cost[n] << endl;
    return 0;
}