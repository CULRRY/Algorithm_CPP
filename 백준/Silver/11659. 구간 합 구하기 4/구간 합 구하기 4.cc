#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    vector<int> sum(N+1);
    for (int i = 1; i <= N; i++)
    {
        if (i == 1)
        {
            sum[i] = v[i];
            continue;
        }
        sum[i] = sum[i-1] + v[i];
    }
    while (M--)
    {
        int start, end;
        cin >> start >> end;
        cout << sum[end] - sum[start - 1] << "\n";
    }

    return 0;
}