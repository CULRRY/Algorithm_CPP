#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> cost(200001, 987654321);

    deque<int> q;
    q.push_back(N);
    cost[N] = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop_front();

        if (now == K)
            break;

        
        if (now != 0 && now <= 100000 && cost[now] < cost[now * 2])
        {
            cost[now*2] = cost[now];
            q.push_front(now * 2);
        } 

        if (now < 200000 && cost[now] + 1 < cost[now + 1])
        {
            cost[now + 1] = cost[now] + 1;
            q.push_back(now + 1);
        }

        if (now > 0 && cost[now] + 1 < cost[now - 1])
        {
            cost[now - 1] = cost[now] + 1;
            q.push_back(now - 1);
        }
    }

    cout << cost[K];
    

    return 0;
}