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
    vector<int> v(n, 0);
    for (int& i : v)
        cin >> i;
    
    if (std::prev_permutation(v.begin(), v.end()))
    {
        for (int i : v)
            cout << i << " ";
    }
    else
    {
        cout << -1;
    }



    return 0;
}