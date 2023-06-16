#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

struct Meet
{
    int s, e;
};

int main()
{
    FASTIO;

    int n;

    cin >> n;
    vector<Meet> m(n);

    for (int i = 0; i < n; i++)
    {
        cin >> m[i].s >> m[i].e;
    }

    sort(m.begin(), m.end(), [](Meet& m1, Meet& m2)
    {
        if (m1.s == m2.s)
        {
            return m1.e < m2.e;
        }
        else
            return m1.s < m2.s;
    });

    vector<int> ans = {0};

    for (Meet meet : m)
    {
        int flag = false;
        for (int i = 0; i < ans.size(); i++)
        {
            if (meet.s >= ans[i])
            {
                ans[i] = meet.e;
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            ans.push_back(meet.e);
        }
    }

    cout << ans.size();

    return 0;
}