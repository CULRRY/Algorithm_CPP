#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<vector<int>> opt(n, vector<int>(n, 0));
    vector<vector<bool>> canRoad(n, vector<bool>(n, true));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> opt[i][j];
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (k == i || k == j)
                    continue;
                
                if (opt[i][j] == opt[i][k] + opt[k][j])
                    canRoad[i][j] = false;
                
                if (opt[i][j] > opt[i][k] + opt[k][j])
                {
                    cout << -1 << endl;
                    return 0;
                }
                
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (canRoad[i][j] == true)
                ans += opt[i][j];
        }
    }


    cout << ans / 2;
    return 0;
}