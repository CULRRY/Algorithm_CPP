#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }   

    sort(v.begin(), v.end());
    
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum += v[j];
        }
    }

    cout << sum;

    return 0;
}