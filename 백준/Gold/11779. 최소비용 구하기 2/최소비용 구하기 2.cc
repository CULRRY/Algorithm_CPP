#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 987654321;
struct Edge
{
    int dest, weight;
};

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    vector<vector<Edge>> adj(n+1, vector<Edge>());

    for (int i = 0; i < m; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;

        adj[v1].push_back({v2, w});
    }
    int s, e;
    cin >> s >> e;

    vector<int> cost(n+1, INF);
    vector<int> via(n+1, 0);
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});

    while(!pq.empty())
    {
        int now  = pq.top().second;
        int nowCost = -pq.top().first;
        pq.pop();

        if (nowCost > cost[now])
            continue;
        
        for (int i = 0; i < adj[now].size(); i++)
        {
            int next = adj[now][i].dest;
            int nextCost = nowCost + adj[now][i].weight;
            if (cost[next] > nextCost)
            {
                cost[next] = nextCost;
                via[next] = now;
                pq.push({-nextCost, next});
            }
        }
    }

    cout << cost[e] << "\n";

    int node = e;
    stack<int> st;
    st.push(node);
    while (node != s)
    {
        st.push(via[node]);
        node = via[node];
    }

    cout << st.size() << "\n";

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }


    return 0;
}