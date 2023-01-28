#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int& i : v)
        cin >> i;
    
    if (next_permutation(v.begin(), v.end()))
    {
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}