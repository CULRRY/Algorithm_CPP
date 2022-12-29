#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

using ull = unsigned long long;
vector<ull> pre(55, 0);


ull cal (ull x)
{
    ull ans = x & 1;

    for (int i = 54; i > 0; i--)
    {
        if (x & (1LL << i))
        {
            ans += pre[i-1] + (x - (1LL << i) + 1);
            x -= 1LL << i;
        }
    }

    return ans;
}


int main()
{
    FASTIO;

    pre[0] = 1;
    
    for (int i = 1; i < 55; i++)
    {
        pre[i] = 2 * pre[i-1] + (1LL << i);
    }

    ull a, b;
    cin >> a >> b;
    cout << cal(b) - cal(a-1);

    return 0;
}