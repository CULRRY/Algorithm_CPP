#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n, m;
int v1, v2;
vector<vector<int>> graph;

int bfs()
{
    vector<bool> discoverd(n+1, false);
    queue<int> q;
    q.push(v1);
    discoverd[v1] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            int now = q.front();
            q.pop();
            if (now == v2)
                return cnt;
            
            for (int next : graph[now])
            {
                if (discoverd[next] == true)
                    continue;
                
                discoverd[next] = true;
                q.push(next);
            }
        }
        cnt++;
    }
    
    return -1;
}

int main()
{
    FASTIO;


    cin >> n;
    graph.assign(n+1, vector<int>());
    cin >> v1 >> v2;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[y].push_back(x);
        graph[x].push_back(y);
    }

    cout << bfs() << endl;
    return 0;
}