#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> items(N + 1);
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        int w, v;
        cin >> w >> v;
        items[i] = make_pair(w, v);
    }


    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (j - items[i].first < 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j - items[i].first] + items[i].second);
        }
    }

    cout << dp[N][K];



    return 0;
}