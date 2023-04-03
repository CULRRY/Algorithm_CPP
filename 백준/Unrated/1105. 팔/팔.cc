#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    string L, R;
    cin >> L >> R;


    int ans = 0;
    if (L.size() != R.size())
    {
        ans = 0;
    }
    else
    {
        for (int i = 0; i < L.size(); i++)
        {
            if (R[i] != L[i])
                break;
            
            if (R[i] == '8' && L[i] == '8')
                ans++;
        }
    }

    cout << ans;

    return 0;
}