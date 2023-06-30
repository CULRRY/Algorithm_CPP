#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;
    vector<int> a(n, 0);
    vector<int> b(m, 0);

    for (int& i : a)
        cin >> i;
    for (int& i : b)
        cin >> i;

    vector<int> ret;

    int i = 0, j = 0;

    for (; i < n && j < m;)
    {
        if (a[i] >= b[j])
            ret.push_back(b[j++]);
        else
            ret.push_back(a[i++]);
    }

    while (i < n)
        ret.push_back(a[i++]);
    while (j < m)
        ret.push_back(b[j++]);
    
    
    for (int i : ret)
        cout << i << " ";

    return 0;
}