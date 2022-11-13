#include <bits/stdc++.h>
using namespace std;

void print_uint128(__uint128_t a)
{
    string s;
    
    while (a > 0)
    {
        int tmp = a % 10;
        s += to_string(tmp);
        a /= 10;
    }

    for (int i = s.size()-1; i >= 0; i--)
    {
        cout << s[i];
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    __uint128_t result = 1;
    cin >> n >> m;
    list<int> l;

    for (int i = 2; i <= m; i++)
    {
        l.push_back(i);
    }

    for (int i = n; i > n-m; i--)
    {
        result *= i;

        for (auto it = l.begin(); it != l.end();)
        {
            if (result % *it == 0)
            {
                result /= *it;
                it = l.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }

    print_uint128(result);
    return 0;
}