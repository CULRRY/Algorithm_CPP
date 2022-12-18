#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> inOrder;
vector<int> postOrder;
vector<int> in_index;

void preOrder(int si, int ei, int sp, int ep)
{
    if (si > ei || sp > ep)
        return;
    
    int root = postOrder[ep];
    cout << root << " ";

    int cnt = in_index[root];

    int l_size = cnt - si;

    preOrder(si, si + l_size-1, sp, sp + l_size-1);
    preOrder(si + l_size + 1, ei, sp + l_size, ep - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    inOrder.assign(n+1, -1);
    in_index.assign(n+1, -1);
    postOrder.assign(n+1, -1);

    for (int i = 1; i <= n; i++)
    {
        cin >> inOrder[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> postOrder[i];
    }

    for (int i = 1; i <= n; i++)
    {
        in_index[inOrder[i]] = i;
    }
    preOrder(1, n, 1, n);
    return 0;
}