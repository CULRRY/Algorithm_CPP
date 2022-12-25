#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    FASTIO;

    int n, k;
    string b;
    cin >> n >> k >> b;


    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 'H')
            continue;
        else if (b[i] == 'P')
        {
            for (int j = -k; j <= k; j++)
            {
                if (i + j < 0 || i + j > n - 1)
                    continue;
                if (b[i + j] == 'H')
                {
                    b[i + j] = 'X';
                    cnt++;
                    break;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}