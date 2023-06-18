#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> pre(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int a;
            cin >> a;

            pre[i][j] = a + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    int k;
    cin >> k;

    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1 -1][y1 - 1] << endl;
    }
    
    

    return 0;
}