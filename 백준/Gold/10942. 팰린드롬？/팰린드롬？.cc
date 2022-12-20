#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;
vector<int> seq;

bool CheckPelindrome(int left, int right)
{
    while (left < right)
    {
        if (seq[left] != seq[right])
            return false;

        left++;
        right--;
    }

    return true;
}

int main()
{
    FASTIO;

    int n;
    cin >> n;

    seq.assign(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> seq[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
        if (seq[i] == seq[i+1])
            dp[i][i+1] = 1;
    }

    for (int d = 2; d < n; d++)
    {
        for (int i = 1; i <= n - d; i++)
        {
            int j = i + d;
            if (seq[i] == seq[j])
            {
                dp[i][j] = dp[i + 1][j - 1];
            }
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;

        cout << dp[s][e] << "\n";
    }

    return 0;
}