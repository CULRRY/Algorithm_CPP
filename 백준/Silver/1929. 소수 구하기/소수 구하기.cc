#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;
    vector<int> v(N+1);
    v[0] = 0, v[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        v[i] = i;
    }

    for (int i = 2; i <= sqrt(N); i++)
    {
        if (v[i] == 0)
            continue;
        
        for (int j = i*i; j <= N; j += i)
        {
            v[j] = 0;   
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (v[i] != 0)
            cout << v[i] << "\n";
    }

    return 0;
}