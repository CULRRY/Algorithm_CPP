#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

vector<int> parent;

int Find(int p)
{
    if (p == parent[p])
        return p;
    
    return parent[p] = Find(parent[p]);
}

void Union(int p, int q)
{
    parent[p] = Find(parent[q]);
}

int main()
{
    FASTIO;

    int g, p;
    cin >> g >> p;

    parent = vector<int>(g + 1);
    std::iota(parent.begin(), parent.end(), 0);
    int size = 0;
    for (int i = 1; i <= p; i++)
    {
        int gi;
        cin >> gi;
        
        if (Find(gi) == 0)
            break;
        
        Union(Find(gi), Find(gi) - 1);
        size++;
    }

    cout << size;

    return 0;
}