#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

struct Delete
{
    int score;
    string s;
};

vector<int> DP(1001, 0);
string s;
vector<Delete> x;
int dp(int idx)
{
    if (DP[idx] != 0)
        return DP[idx];
    if (idx >= s.size())
        return 0;
    int ret = 0;

    for (Delete d : x)
    {
        if (d.s == s.substr(idx, d.s.size()))
            ret = std::max(ret, dp(idx + d.s.size()) + d.score);
    }

    ret = std::max(ret, dp(idx + 1) + 1);

    return DP[idx] = ret;
}

int main()
{
    FASTIO;

    cin >> s;

    int m;
    cin >> m;

    x.resize(m);

    for (auto &i : x)
        cin >> i.s >> i.score;

    cout << dp(0);

    return 0;
}