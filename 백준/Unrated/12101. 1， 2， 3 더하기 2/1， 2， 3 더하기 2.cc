#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n, k;
vector<string> exprs;

void bt(int sum, string expr)
{
    if (sum == n)
    {
        exprs.push_back(expr);
    }
    
    if (sum > n)
    {
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        bt(sum + i, expr + "+" + to_string(i));
    }
}

int main()
{
    FASTIO;

    cin >> n >> k;    

    for (int i = 1; i <= 3; i++)
    {
        bt(i, to_string(i));
    }

    sort(exprs.begin(), exprs.end());

    if (exprs.size() < k)
        cout << -1;
    else
        cout << exprs[k-1];

    return 0;
}