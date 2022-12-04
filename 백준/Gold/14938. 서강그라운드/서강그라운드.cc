#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 9876543;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> dis(n+1, vector<int>(n+1, INF));
    vector<int> item(n+1, 0);
    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
        cin >> item[i];
    }

    for (int i = 0; i < r; i++)
    {
        int s, e, w;
        cin >> s >> e >> w;
        
        dis[s][e] = w;
        dis[e][s] = w;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j =1; j <= n; j++)
            {
                dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dis[i][j] <= m)
            {
                tmp += item[j];
            }
        }
        max = std::max(max, tmp);
    }

    cout << max << "\n";


    return 0;
}