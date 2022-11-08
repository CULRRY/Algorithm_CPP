#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    while(b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int lcm (int a, int b)
{
    return a*b / gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int now_y;

        int end = lcm(N, M);
        for (int k = x; k <= end; k += M)
        {
            now_y = (k % N);
            if (now_y == 0)
                now_y = N;
            if (now_y == y)
            {
                cout << k << "\n";
                break;
            }
            
            if (k + M > end)
            {
                cout << -1 << "\n";
                break;
            }
        }
    }

    return 0;
}