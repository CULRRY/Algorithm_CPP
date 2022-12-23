#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

constexpr int INF = 987654321;

const vector<int> loop = {4, 1, 2, 3, 4, 1};

int cost(int now, int dest)
{
    if (now == dest)
        return 1;
    
    if (now == 0)
        return 2;
    
    if (loop[now-1] == dest || loop[now+1] == dest)
        return 3;
    
    return 4;
}


int main()
{
    FASTIO;

    int n;
    cin >> n;

    vector<int> ddr;
    ddr.push_back(0);
    while (n != 0)
    {
        ddr.push_back(n);
        cin >> n;
    }

    vector<vector<vector<int>>> dp(ddr.size(), vector<vector<int>>(5, vector<int>(5, INF))); 
    dp[0][0][0] = 0;

    for (int i = 1; i < ddr.size(); i++)
    {
        for (int left = 0; left < 5; left++)
        {
            for (int right = 0; right < 5; right++)
            {
                if(dp[i-1][left][right] >= INF) continue;

                int leftCost = cost(left, ddr[i]);
                int rightCost = cost(right, ddr[i]);

                dp[i][left][ddr[i]] = std::min(dp[i][left][ddr[i]], dp[i-1][left][right] + rightCost);
                dp[i][ddr[i]][right] = std::min(dp[i][ddr[i]][right], dp[i-1][left][right] + leftCost);
            }
        }
    }
    
    int result = INF;
    for (int left = 0; left < 5; left++)
    {
        for (int right = 0; right < 5; right++)
        {
            result = std::min(result, dp[ddr.size()-1][left][right]);
        }
    }

    cout << result;

    

    return 0;
}