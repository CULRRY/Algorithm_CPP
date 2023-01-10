#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

struct Point
{
    double x, y;
};

int main()
{
    FASTIO;

    int v, m;
    cin >> v >> m;

    Point start;
    Point dest;
    cin >> start.x >> start.y;
    cin >> dest.x >> dest.y;

    vector<Point> bunker;
    bunker.push_back(start);
    bunker.push_back(dest);

    while (!cin.eof())
    {
        double x, y;
        cin >> x >> y;
        bunker.push_back({x, y});
    }

    double maxDistance = 60 * v * m;
    
    vector<vector<int>> adj(bunker.size(), vector<int>());

    for (int i = 0; i < bunker.size(); i++)
    {
        for (int j = 0; j < bunker.size(); j++)
        {
            if (sqrt(pow(bunker[i].x - bunker[j].x, 2) + pow(bunker[i].y-bunker[j].y, 2)) <= maxDistance)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<bool> discoverd(bunker.size(), false);
    queue<int> q;
    q.push(0);
    discoverd[0] = true;
    int cnt = 0;
    bool success = false;
    while (!q.empty())
    {
        int sz = q.size();
        for (int c = 0; c < sz; c++)
        {
            int now = q.front();
            q.pop();
            if (now == 1)
            {
                cout << "Yes, visiting " << cnt - 1 << " other holes.";
                success = true;
                break;
            }
            for (int next : adj[now])
            {
                if (discoverd[next] == true)
                    continue;
                
                q.push(next);
                discoverd[next] = true;
            }
        }
        cnt++;
    }

    if (success == false)
        cout << "No." << endl;
    

    return 0;
}