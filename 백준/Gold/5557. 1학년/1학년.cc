#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

using ull = unsigned long long;

enum { PLUS, MINUS };
int n;
vector<int> oprand;
int ans;


int main()
{
    FASTIO;


    cin >> n;

    oprand = vector<int>(n - 1, 0);
    ans = 0;

    for (int i = 0; i < n-1; i++)
    {
        cin >> oprand[i];
    }
    cin >> ans;

    vector<vector<ull>> dp(n-1, vector<ull>(21, 0));

    dp[0][oprand[0]] = 1;

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (dp[i-1][j] == 0)
                continue;
            
            if (j + oprand[i] <= 20)
                dp[i][j + oprand[i]] += dp[i-1][j];
            if (j - oprand[i] >= 0)
                dp[i][j - oprand[i]] += dp[i-1][j];
        }
    }

    cout << dp[n-2][ans];

    return 0;
}