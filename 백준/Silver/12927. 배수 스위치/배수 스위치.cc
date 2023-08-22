#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    string s;
    cin >> s;
    int n = s.size();
    int left = 0;
    int ans = 0;
    vector<bool> bulb(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'Y')
        {
            bulb[i+1] = true;
            left++;
        }
    }


    for (int i = 1; i <= n; i++)
    {
        if (bulb[i] == false)
            continue;
        
        if (left == 0)
        {
            break;
        }

        ans++;
        for (int j = i; j <= n; j += i)
        {
            bulb[j] = !bulb[j];
            if (bulb[j] == true)
                left++;
            else
                left--;
        }
    }

    if (left != 0)
    {
        ans = -1;
    }

    cout << ans << endl;
    



    return 0;
}