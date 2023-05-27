#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n, k;
vector<int> d;
vector<int> r;

void belt()
{
    for (int i = 1; i <= 2*n - 1; i++)
    {
        ::swap(d[i], d[2*n]);
        ::swap(r[i], r[2*n]);
    }
}

int oper()
{
    int t = 0;
    while (true)
    {
        t++;
        belt();
        if (r[n] != -1)
        {
            r[n] = -1;
        }

        for (int i = 2 * n; i >= 1; i--)
        {
            int pos = i;

            if (r[i] == -1)
                continue;

            if (d[(pos + 1) % (2*n)] > 0 && r[(pos + 1) % (2*n)] == -1)
            {
                r[(pos + 1) % (2*n)] = 1;
                r[pos] = -1;
                d[(pos + 1) % (2*n)]--;
                pos = (pos+1) % (2*n);
                if (pos == n)
                {
                    r[n] = -1;
                }
            }
        }

        if (d[1] > 0)
        {
            r[1] = 1;
            d[1]--;
        }

        int cnt = 0;
        for (int i = 1; i <= 2*n; i++)
        {
            if (d[i] <= 0)
                cnt++;
        }

        if (cnt >= k)
            return t;
        

    }
    
    return -1;
}


int main()
{
    FASTIO;

    cin >> n >> k;

    d = vector<int>(2*n+1, 0);
    r = vector<int>(2*n+1, -1);

    for (int i = 1; i <= 2*n; i++)
        cin >> d[i];
    
    cout << oper();

    return 0;
}