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
    int ans = -987654321;
    vector<vector<int>> arr(n+1, vector<int>(n+1, 0));
    vector<vector<int>> pre(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            ans = std::max(arr[i][j], ans);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pre[i][j] = arr[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    for (int k = 1; k < n; k++)
    {
        for (int i = 1; i <= n - k; i++)
        {
            for (int j = 1; j <= n - k; j++)
            {
                int sum = pre[i+k][j+k] - pre[i-1][j+k] - pre[i+k][j-1] + pre[i-1][j-1];
                ans = std::max(sum, ans);
            }
        }
    }

    cout << ans;



    return 0;
}