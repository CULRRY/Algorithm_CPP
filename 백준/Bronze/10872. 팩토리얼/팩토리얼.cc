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
    int ans = 1;

    for (int i = 1; i <= n; i++)
    {
        ans *= i;
    }

    cout << ans << endl;

    return 0;
}