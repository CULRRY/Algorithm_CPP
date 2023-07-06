#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << "*";
        cout << endl;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
            cout << "*";
        cout << endl;
    }

    return 0;
}