#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> upDP(n, 0);

    for (int i = 0; i < n; i++)
    {
        upDP[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                upDP[i] = std::max(upDP[j] + 1, upDP[i]); 
            }
        }
    }

    vector<int> downDP(n, 0);
    
    for (int i = n-1; i >= 0; i--)
    {
        downDP[i] = 1;
        for (int j = n-1; j > i; j--)
        {
            if (a[j] < a[i])
            {
                downDP[i] = std::max(downDP[j] + 1, downDP[i]);
            }
        }
    }

    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        dp[i] = upDP[i] + downDP[i] - 1;
    }

    cout << *max_element(dp.begin(), dp.end());


    return 0;
}