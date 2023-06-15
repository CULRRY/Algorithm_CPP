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

    vector<int> in(n+1, 0);
    vector<int> out(n+1, 0);
    for (int i = 0; i < n-1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        in[v1]++;
        in[v2]++;
        out[v1]++;
        out[v2]++;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int t, k;
        cin >> t >> k;

        if (t == 1)
        {
            if (in[k] == 1 && out[k] == 1)
                cout << "no" << endl;
            else
                cout << "yes" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }

    return 0;
}