#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    long long x, y;
    cin >> x >> y;

    long long n = 1;
    long long sum = 0;

    while (true)
    {
        sum += n;

        if (sum < x + y)
        {
            n++;
            continue;
        }
        else if (sum == x + y)
        {
            break;
        }
        else
        {
            cout << -1;
            return 0;
        }
    }

    long long sub = n;
    long long cnt = 0;
    while (x > 0)
    {
        if (sub > x)
        {
            sub--;
            continue;
        }
        else
        {
            x -= sub;
            sub--;
            cnt++;
        }
        
    }

    cout << cnt;
    
    


    return 0;
}