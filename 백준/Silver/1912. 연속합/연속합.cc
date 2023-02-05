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
    int sum = 0;
    vector<int> pre(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    vector<int> dp(n, 0);
    dp[0] = pre[0];
    for (int i = 1; i < n; i++)
    {
        dp[i] = std::max(dp[i-1] + pre[i], pre[i]);
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}