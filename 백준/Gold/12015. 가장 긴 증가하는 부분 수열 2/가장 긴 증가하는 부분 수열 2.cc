#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;



int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> result;

    for (int& i : v) cin >> i;

    result.push_back(v[0]);

    for (int i = 1; i < n; i++)
    {
        if (v[i] > result.back())
        {
            result.push_back(v[i]);
        }
        else
        {
            *std::lower_bound(result.begin(), result.end(), v[i]) = v[i];
        }
    }

    cout << result.size();



    return 0;
}