#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    int max = 0;
    vector<int> dp(N, 0);
    for (int i = 0; i < N; i++)
    {
        dp[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i])
            {
                dp[i] = std::max(dp[j] + 1, dp[i]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";

    return 0;
}