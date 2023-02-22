#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int n, m;
vector<int> parent;

int Find(int p)
{
    if (parent[p] == p)
        return p;
    
    return parent[p] = Find(parent[p]);
}

void Union(int p, int q)
{
    parent[Find(p)] = Find(q);
}

bool isEqual(int p, int q)
{
    return Find(p) == Find(q);
}

int main()
{
    FASTIO;
    cin >> n >> m;
    parent = vector<int>(n+1);
    std::iota(parent.begin(), parent.end(), 0);

    while (m--)
    {
        int k, a, b;
        cin >> k >> a >> b;
        if (k == 0)
        {
            Union(a, b);
        }
        else
        {
            if (isEqual(a, b))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }

    

    return 0;
}