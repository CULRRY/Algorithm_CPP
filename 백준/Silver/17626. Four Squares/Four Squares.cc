#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n+1, 0);
    int sqrt_n = (int)sqrt(n);
    for (int i = 0; i <= n; i++)
    {
        v[i] = i;
    }
    for (int i = 2; i <= sqrt_n; i++)
    {
        for (int j = i*i; j <= n; j++)
        {
            v[j] = std::min(v[j], v[j - i*i] + 1);
        }
    }


    cout << v[n] << "\n";



    return 0;
}