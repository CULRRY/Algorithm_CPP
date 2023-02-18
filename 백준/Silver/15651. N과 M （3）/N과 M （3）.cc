#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int n, m;
vector<int> v;

void bt(int depth)
{
    if (depth == m)
    {
        for (int i : v)
            cout << i << " ";
        cout << endl;

        return;
    }

    for (int i = 1; i <= n; i++)
    {
        v[depth] = i;
        bt(depth + 1);
    }
}

int main()
{
    FASTIO;

    cin >> n >> m;
    v = vector<int>(m);
    bt(0);

    return 0;
}