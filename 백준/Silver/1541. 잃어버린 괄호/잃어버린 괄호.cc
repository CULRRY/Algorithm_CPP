#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums;
    vector<char> operators;

    string full;
    cin >> full;
    string num = "";
    for (int i = 0; i < full.size(); i++)
    {
        if (full[i] == '+' || full[i] == '-')
        {
            operators.push_back(full[i]);
            nums.push_back(stoi(num));
            num = "";
        }
        else
        {
            num += full[i];
        }
    }
    nums.push_back(stoi(num));

    vector<vector<int>> dp;
    dp.assign(nums.size(), vector<int>(nums.size()));

    for (int i = 0; i < nums.size(); i++)
    {
        dp[i][i] = nums[i];
    }
    for (int d = 1; d < nums.size(); d++)
    {
        for (int i = 0; i < nums.size() - d; i++)
        {
            int j = i + d;
            int min = 10000000;
            for (int k = i; k < j; k++)
            {
                int sum;
                if (operators[k] == '+')
                    sum = dp[i][k] + dp[k+1][j];
                else
                    sum = dp[i][k] - dp[k+1][j];
                
                if (sum < min)
                    min = sum;
            }
            dp[i][j] = min;
        }
    }
    cout << dp[0][nums.size()-1];
    return 0;
}