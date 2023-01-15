#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        
        vector<int> primes(2*n+1, 0);
        for (int i = 2; i <= 2*n; i++)
        {
            primes[i] = i;
        }

        for (int i = 2; i <= sqrt(2*n); i++)
        {
            if (primes[i] == 0)
                continue;
            
            for (int j = i*i; j <= 2*n; j += i)
            {
                primes[j] = 0;
            }
        }
        
        int cnt = 0;
        for (int i = n+1; i <= 2*n; i++)
        {
            if (primes[i] != 0)
            {
                cnt++;
            }
        }

        cout << cnt << endl;
    }
    

    return 0;
}