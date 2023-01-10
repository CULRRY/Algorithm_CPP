#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

vector<int> v;
vector<int> s;
vector<long long> pre;
vector<long long> ans;

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;
    v = vector<int>(n);
    s = vector<int>(n);
    pre = vector<long long>(n + 1);
    ans = vector<long long>(n + 1);


    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = y;
        s[i] = y;
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < m; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        v1--; v2--;
        int h1 = v[v1];
        int h2 = v[v2];
        if (h1 > h2)
            swap(h1, h2);

        int start = lower_bound(s.begin(), s.end(), h1) - s.begin();
        int end = upper_bound(s.begin(), s.end(), h2) - s.begin();
        pre[start] += w;
        pre[end] -= w;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pre[i];
        ans[i] = sum;
    }

    cout << *max_element(ans.begin(), ans.end());
    return 0;
}