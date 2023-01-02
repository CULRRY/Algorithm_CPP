#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

void makePal(vector<vector<bool>>& p, int size, string& s)
{
    for (int i = 0; i < size; i++)
    {
        p[i][i] = true;
        if (i + 1 < size && s[i] == s[i + 1]) 
            p[i][i+1] = true;
    }

    for (int i = 2; i < size; i++)
    {
        for (int j = 0; i + j < size; j++)
        {
            if (s[j] == s[i + j] && p[j+1][i+j-1]) 
                p[j][i+j] = true;
        }
    }
}


int main()
{
    FASTIO;

    string s;
    cin >> s;
    vector<int> dp(s.size() + 1, 99998788);
    vector<vector<bool>> pel(s.size() + 1, vector<bool>(s.size()+1, false));
    makePal(pel, s.size(), s);
    dp[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (pel[j][i])
            {
                if ( j == 0)
                    dp[i] = std::min(dp[i], 1);
                else
                    dp[i] = std::min(dp[i], dp[j - 1] + 1);   
            }
        }
    }

    cout << dp[s.size()-1];

    return 0;
}