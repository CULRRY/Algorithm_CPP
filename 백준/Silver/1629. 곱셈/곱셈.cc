#include <bits/stdc++.h>
using namespace std;

long long mul(long long a, long long b, long long c)
{
    if (b == 0)
        return 1;
    
    
    if (b%2 == 0)
    {
        long long tmp = mul(a % c, b / 2, c);
        return ((tmp % c) * (tmp % c)) % c;
    }
    else
    {
        long long tmp = mul(a % c, (b - 1) / 2, c);
        return (tmp % c * tmp % c * a % c) % c;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c;

    cin >> a >> b >> c;

    cout << mul(a, b, c) % c;

    return 0;
}