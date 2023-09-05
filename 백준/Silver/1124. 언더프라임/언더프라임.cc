#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int a, b;
    cin >> a >> b;

    vector<bool> prime(b+1, true);
    prime[1] = false;

    for (int i = 2; i <= b; i++)
    {
        if (prime[i] == false)
            continue;
        
        for (int j = 2 * i; j <= b; j += i)
        {
            prime[j] = false;
        }
    }
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        int n = i;
        int cnt = 0;
        for (int j = 2; j <= b; j++)
        {
            if (prime[j] == false)
                continue;
            
            if (n == 1)
            {
                break;
            }

            while (n % j == 0)
            {
                cnt++;
                n /= j;
            }
            
        }
        
        if (prime[cnt] == true)
            ans++;
    }

    cout << ans << endl;
    return 0;
}