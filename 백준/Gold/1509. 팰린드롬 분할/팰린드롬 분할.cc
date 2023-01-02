#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    FASTIO;

    string s;
    cin >> s;
    vector<int> dp(s.size() + 1, 99998788);
    dp[0] = 1;

    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int left = j;
            int right = i;
            bool isPelindrome = true;
            while (left <= right)
            {
                if (s[left] != s[right])
                {
                    isPelindrome = false;
                    break;
                }
                left++;
                right--;
            }
            if (isPelindrome)
            {
                if (j == 0)
                {
                    dp[i] = 1;
                }
                else
                {
                    dp[i] = std::min(dp[j - 1] + 1, dp[i]);
                }
            }
        }
    }

    cout << dp[s.size()-1];

    return 0;
}