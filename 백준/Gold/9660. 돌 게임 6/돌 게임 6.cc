#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using ull = unsigned long long;
using namespace std;

int main()
{
    FASTIO;

    ull n;
    cin >> n;

    if (n % 7UL == 0 || n % 7UL == 2)
    {
        cout << "CY" << endl;
    }
    else
    {
        cout << "SK" << endl;
    }

    return 0;
}