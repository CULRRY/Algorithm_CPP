#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
enum {RIGHT, LEFT};
vector<int> cards;
int dp[1000][1000][2];
int solve(int left, int right, int turn)
{
    int& ret = dp[left][right][turn];
    if (ret != -1) return ret;

    if (left >= right)
    {
        if (turn == 0)
            return ret = cards[left];
        else return ret = 0; 
    }

    if (turn == 0)
    {
        return ret = std::max(solve(left + 1, right, 1) + cards[left], solve(left, right - 1, 1) + cards[right]);
    }
    else
    {
        return ret = std::min(solve(left + 1, right, 0), solve(left, right - 1, 0));
    }
}


int main()
{
    FASTIO;

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            cards.push_back(a);
        }
        cout << solve(0, n-1, 0) << endl;
        cards.clear();
    }
    

    return 0;
}