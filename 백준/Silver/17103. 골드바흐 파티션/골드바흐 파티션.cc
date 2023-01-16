#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    vector<bool> v(1000001, true);

    for (int i = 2; i <= 1000; i++)
    {
        if (v[i] == false)
            continue;

        for (int j = i*i; j <= 1000000; j += i)
        {
            v[j] = false;
        }
    }

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 2; i <= n / 2; i++)
        {
            if (!v[i])
                continue;
            
            int otherside = n - i;
            if (v[n-i])
                cnt++;
        }

        cout << cnt << endl;
    }
    

    return 0;
}