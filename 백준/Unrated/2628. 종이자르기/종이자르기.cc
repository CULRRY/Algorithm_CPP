#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    int w, h;
    cin >> w >> h;

    vector<int> hor;
    vector<int> ver;

    hor.push_back(0);
    hor.push_back(w);
    ver.push_back(0);
    ver.push_back(h);

    int n;
    cin >> n;
    while (n--)
    {
        int axis, idx;
        cin >> axis >> idx;

        if (axis == 1)
            hor.push_back(idx);
        else
            ver.push_back(idx);
    }

    sort(hor.begin(), hor.end());
    sort(ver.begin(), ver.end());

    int ans = 0;
    for (int i = 1; i < hor.size(); i++)
    {
        for (int j = 1; j < ver.size(); j++)
        {
            ans = std::max(ans, (hor[i] - hor[i-1]) * (ver[j] - ver[j-1]));
        }
    }

    cout << ans;
    

    return 0;
}