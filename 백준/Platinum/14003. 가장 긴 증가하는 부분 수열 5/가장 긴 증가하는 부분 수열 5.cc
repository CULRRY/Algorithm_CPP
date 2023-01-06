#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

void recur(vector<int>& a, vector<int>& p, int norm, int now)
{
    if (now < 0)
        return;

    if (p[now] == norm)
    {
        recur(a, p, norm - 1, now - 1);
        cout << a[now] << " ";
    }
    else
    {
        recur(a, p, norm, now - 1);
    }
}


int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> p(n);
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    result.push_back(a[0]);
    p[0] = 0;

    for (int i = 1; i < n; i++)
    {
        auto lw = lower_bound(result.begin(), result.end(), a[i]);
        if (lw != result.end())
        {
            p[i] = lw - result.begin();
            *lw = a[i];
        }
        else
        {
            p[i] = result.size();
            result.push_back(a[i]);
        }
    }

    cout << result.size() << "\n";


    recur(a, p, result.size() - 1, n - 1);


    return 0;
}