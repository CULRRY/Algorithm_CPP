#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<int> v(n+1, 0);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        v[i] = sum;
    }

    int interval;
    cin >> interval;
    vector<vector<int>> dp(4, vector<int>(n+1, 0));
    dp[1][0] = 0;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = (i) * (interval - 1); j <= n - (interval - 1) ; j++)
        {
            if (j >= interval)
                dp[i][j] = std::max(dp[i][j-1], dp[i-1][j-interval] + v[j + interval - 1] - v[j - 1]);
            else
            {
                dp[i][j] = v[j + interval - 1] - v[j - 1];
            }
        }
    }
    cout << *max_element(dp[3].begin(), dp[3].end()) << endl;

    return 0;
}