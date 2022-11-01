#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> score(N+1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> score[i];
    }

    vector<int> dp(N + 1);
    vector<int> count(N + 1);
    dp[0] = score[0]; dp[1] = score[1]; dp[2] = score[1] + score[2];
    count[0] = 0; count[1] = 1; count[2] = 2;
    for (int i = 3; i <= N; i++)
    {
        int max = 0;
        if (dp[i-2] + score[i] > max)
        {
            max = dp[i-2] + score[i];
            count[i] = 1;
        }
        
        if (dp[i-1] + score[i] > max && count[i-1] < 2)
        {
            max = dp[i - 1] + score[i];
            count[i] = count[i-1] + 1;
        }

        if (dp[i-3] + score[i-1] + score[i] > max)
        {
            max = dp[i-3] + score[i-1] + score[i];
            count[i] = 2;
        }
        dp[i] = max;
    }

    cout << dp[N];
    return 0;
}