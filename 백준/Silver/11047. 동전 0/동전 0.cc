#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    int count = 0;
    cin >> N >> K;
    vector<int> coins(N);
    for (int i = 0; i < N; i++)
    {
        cin >> coins[i];
    }

    for (int i = N-1; i >= 0; i--)
    {
        while (K >= coins[i])
        {
            K -= coins[i];
            count++;
        }
    }

    cout << count;


    return 0;
}