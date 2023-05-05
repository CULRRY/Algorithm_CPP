#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int n, m;
vector<vector<int>> arr;

int main()
{
    FASTIO;

    cin >> n >> m;
    arr = vector<vector<int>>(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] != 0)
            {
                arr[i][j] = std::min(arr[i-1][j-1], std::min(arr[i-1][j], arr[i][j-1])) + 1;
                ans = std::max(ans, arr[i][j]);
            }

        }
    }

    cout << ans * ans << endl;

    return 0;
}