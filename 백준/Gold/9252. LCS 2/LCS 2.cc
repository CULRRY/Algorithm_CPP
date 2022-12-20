#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    FASTIO;

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    vector<vector<int>> memo(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    int l1 = s1.length();
    int l2 = s2.length();


    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                memo[i][j] = 0;
            }
            else
            {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                if (dp[i][j] == dp[i-1][j])
                {
                    memo[i][j] = 1;
                }
                else
                    memo[i][j] = 2;
            }
        }
    }

    cout << dp[l1][l2] << "\n";
    stack<char> s;
    int i = l1 , j = l2;
    while (i != 0 && j != 0)
    {
        if (memo[i][j] == 0)
        {
            s.push(s1[i-1]);
            i = i -1;
            j = j -1;
        }
        else if (memo[i][j] == 1)
        {
            i = i-1;
            j = j;
        }
        else
        {
            i = i;
            j = j - 1;
        }
        
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}