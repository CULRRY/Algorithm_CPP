#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

int main()
{
    FASTIO;

    int n, k;
    cin >> n >> k;
    vector<double> dis(n);
    
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        double max = 0;
        for (int i = 0; i < p; i++)
        {
            double x, y;
            cin >> x >> y;
            double dis = pow(x,2) + pow(y,2);
            max = std::max(max, dis);
        }
        dis[i] = max;
    }

    sort(dis.begin(), dis.end());

    cout << fixed;
    cout.precision(2);
    cout << dis[k-1];

    return 0;
}