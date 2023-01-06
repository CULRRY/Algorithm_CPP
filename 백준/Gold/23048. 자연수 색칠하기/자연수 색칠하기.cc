#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<int> v(n + 1);
    int cnt = 2;
    vector<int> ans(n + 1);

    for (int i = 2; i <= n; i++)
    {
        v[i] = i;
    }
    ans[1] = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (v[i] == 0)
            continue;
        
        for (int j = i*i; j <= n; j += i)
        {
            v[j] = 0;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (v[i] != 0)
        {
            int j = i;
            while (j <= n)
            {
                ans[j] = cnt;
                j += i;
            }
            cnt++;
        }
        
    }

    cout << cnt - 1 << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}