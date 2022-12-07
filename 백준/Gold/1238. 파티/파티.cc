#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int w, n;
};

constexpr int INF = 987654321;
vector<vector<Node>> adj;
int n, m, x;

void Dijikstra(vector<int>& cost, int start)
{
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    cost[start] = 0;
    while(!pq.empty())
    {
        int nowCost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (nowCost > cost[now])
            continue;

        for (int i = 0; i < adj[now].size(); i++)
        {
            Node next = adj[now][i];
            int nextCost = cost[now] + next.w;
            if (nextCost > cost[next.n])
                continue;
            
            pq.push({-nextCost, next.n});
            cost[next.n] = nextCost;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;
    adj.assign(n+1, vector<Node>());

    for (int i = 0; i < m; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        adj[s].push_back({w, e});
    }

    vector<int> time(n+1, INF);
    Dijikstra(time, x);
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
            continue;
        vector<int> cost(n+1, INF);
        Dijikstra(cost, i);
        time[i] += cost[x];
    }

    cout << *max_element(time.begin()+1, time.end());


    return 0;
}