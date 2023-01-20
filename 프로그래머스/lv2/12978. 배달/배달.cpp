#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define cost first
#define num second
constexpr int INF = 9876554321;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vector<vector<int>> adj(N+1, vector<int>(N+1, INF));
    
    for (vector<int>& r : road)
    {
        int v1 = r[0], v2 = r[1], w = r[2];
        if (adj[v1][v2] > w)
        {
            adj[v1][v2] = w;
            adj[v2][v1] = w;
        }
            
    }
    
    vector<int> cost(N+1, INF);
    priority_queue<pair<int,int>> pq;
    pq.push({0, 1});
    cost[1] = 0;
    while (!pq.empty())
    {
        int nowCost = -pq.top().cost;
        int now = pq.top().num;
        pq.pop();
        
        if (nowCost > cost[now])
            continue;
        
        for (int next = 1; next <= N; next++)
        {
            int nextCost = adj[now][next] + cost[now];
            if (nextCost < cost[next])
            {
                cost[next] = nextCost;
                pq.push({-nextCost, next});
            }
        }

    }
    for (int i: cost)
    {
        if (i <= K)
            answer++;
    }
    

    return answer;
}