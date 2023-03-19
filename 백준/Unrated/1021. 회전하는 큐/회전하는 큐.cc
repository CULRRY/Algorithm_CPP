#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    deque<int> dq;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int target;
        cin >> target;

        deque<int> tmp2(dq);
        deque<int> tmp3(dq);
        int cnt2 = 0;
        int cnt3 = 0;

        while (tmp2.front() != target)
        {
            cnt2++;
            tmp2.push_back(tmp2.front());
            tmp2.pop_front();
        }
        tmp2.pop_front();
        while (tmp3.front() != target)
        {
            cnt3++;
            tmp3.push_front(tmp3.back());
            tmp3.pop_back();
        }
        tmp3.pop_front();
        if (cnt2 <= cnt3)
        {
            ans += cnt2;
            dq = tmp2;
        }
        else
        {
            ans += cnt3;
            dq = tmp3;
        }
    }

    cout << ans << endl;

    return 0;
}