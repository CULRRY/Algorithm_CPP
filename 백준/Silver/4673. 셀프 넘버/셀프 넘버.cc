#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;
vector<bool> v(10001, true);

void d(int n)
{
    if (n > 10000)
        return;

    int next = n;

    while (n != 0)
    {
        next += n % 10;
        n /= 10;
    }

    v[next] = false;

    d(next);
    
}

int main()
{
    FASTIO;

    

    for (int i = 1; i <= 10000; i++)
    {
        if (v[i] == false)
            continue;
        
        d(i);
    }


    for (int i = 1; i <= 10000; i++)
    {
        if (v[i] == true)
            cout << i << endl;
    }


    return 0;
}