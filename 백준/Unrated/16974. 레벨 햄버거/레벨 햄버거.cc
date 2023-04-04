#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
using ull = unsigned long long;

ull n, x;
ull patties[51];
ull layers[51];
ull ans = 0;

void solution(int n)
{
    if (n < 1)
        return;
    if (x == 0)
        return;
    x--;
    if (x >= layers[n-1])
    {
        ans += patties[n-1];
        x -= layers[n-1];
    }
    else
    {
        solution(n-1);
    }
    if (x == 0)
        return;
    x--;
    ans++;

    if (x >= layers[n-1])
    {
        ans += patties[n-1];
        x -= layers[n-1];
    }
    else
    {
        solution(n - 1);
    }
    if (x == 0)
        return;
    x--;
}

int main()
{
    FASTIO;


    cin >> n >> x;

    patties[0] = 1;
    layers[0] = 1;

    for (int i = 1; i <= 50; i++)
    {
        patties[i] = 2 * patties[i-1] + 1;
        layers[i] = 2 * layers[i-1] + 3;
    }

    solution(n);
    cout << ans;

    return 0;
}


