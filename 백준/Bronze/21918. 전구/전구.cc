#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

vector<bool> light;

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;

    light = vector<bool>(n+1, 0);

    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;

        if (t == 0)
            light[i] = false;
        else
            light[i] = true;
    }

    while (m--)
    {
        int c, l, r;
        cin >> c >> l >> r;

        switch (c)
        {
        case 1:
            light[l] = r == 0 ? false : true;
            break;
        case 2:
            for (int i = l; i <= r; i++)
                light[i] = !light[i];
            break;
        case 3:
            for (int i = l; i <= r; i++)
                light[i] = false;
            break;
        case 4:
            for (int i = l; i <= r; i++)
                light[i] = true;
            break;
        default:
            break;
        }

    }

    for (int i = 1; i <= n; i++)
        cout << light[i] << " ";
    

    return 0;
}