#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

struct Star
{
    int i, x, y, z;
};

struct Edge
{
    int v1, v2, weight;
};

vector<int> parent;

int Find(int p)
{
    if (p == parent[p])
        return p;
    
    return parent[p] = Find(parent[p]);
}

void Union(int p, int q)
{
    parent[Find(p)] = Find(q);
}

bool Equal(int p, int q)
{
    return Find(p) == Find(q);
}

int main()
{
    FASTIO;
    int n;
    cin >> n;
    vector<Star> stars(n);
    vector<Edge> edges;
    parent = vector<int>(n);
    ::iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        stars[i] = {i, x, y, z};
    }

    ::sort(stars.begin(), stars.end(), [](const Star& s1, const Star& s2) { return s1.x < s2.x; });
    for (int i = 0; i < n - 1; i++)
    {
        edges.push_back({stars[i].i, stars[i+1].i, abs(stars[i].x - stars[i+1].x)});
    }

    ::sort(stars.begin(), stars.end(), [](const Star& s1, const Star& s2) { return s1.y < s2.y; });
    for (int i = 0; i < n - 1; i++)
    {
        edges.push_back({stars[i].i, stars[i+1].i, abs(stars[i].y - stars[i+1].y)});
    }

    ::sort(stars.begin(), stars.end(), [](const Star& s1, const Star& s2) { return s1.z < s2.z; });
    for (int i = 0; i < n - 1; i++)
    {
        edges.push_back({stars[i].i, stars[i+1].i, abs(stars[i].z - stars[i+1].z)});
    }


    ::sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) { return e1.weight < e2.weight; });

    int cnt = n-1;
    int index = 0;
    int ans = 0;
    while (cnt)
    {
        const Edge e = edges[index];
        int p = e.v1;
        int q = e.v2;

        if (!Equal(p, q))
        {
            Union(p, q);
            ans += e.weight;
            cnt--;
        }

        index++;
    }

    cout << ans;
    


    

    return 0;
}