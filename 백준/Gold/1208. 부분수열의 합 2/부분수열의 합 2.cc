#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;
using ll = long long;
int n, s;
vector<int> v;

void bt(int sum, int index, int end, vector<int> &a)
{
    if (index == end)
    {
        a.push_back(sum);
        return;
    }

    bt(sum, index + 1, end, a);
    bt(sum + v[index], index + 1, end, a);
}

int main()
{
    FASTIO;

    cin >> n >> s;
    v = vector<int>(n, 0);

    for (int &i : v)
        cin >> i;
    vector<int> left;
    vector<int> right;

    bt(0, 0, n / 2, left);
    bt(0, n / 2, n, right);

    sort(right.begin(), right.end());

    ll cnt = 0;
    for (int i = 0; i < left.size(); i++)
    {
        auto lb = std::lower_bound(right.begin(), right.end(), s - left[i]);
        auto ub = std::upper_bound(right.begin(), right.end(), s - left[i]);
        cnt += ub - lb;
    }

    if (s == 0)
    {
        cout << cnt - 1;
    }
    else
        cout << cnt;

    return 0;
}