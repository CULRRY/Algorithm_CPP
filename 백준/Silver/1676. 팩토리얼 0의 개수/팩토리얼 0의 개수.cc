#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int div2 = 0, div5 = 0;
    for (int i = 1; i <= N; i++)
    {
        int tmp = i;
        while ((tmp % 2) == 0)
        {
            tmp /= 2;
            div2++;
        }
        tmp = i;
        while ((tmp % 5) == 0)
        {
            tmp /= 5;
            div5++;
        }
    }

    cout << std::min(div2, div5);

    return 0;
}