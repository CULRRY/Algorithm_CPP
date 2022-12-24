#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;
constexpr float error = 1e-2f;

struct Point
{
    float x, y;
};

struct Edge
{
    int v1, v2;
    float w;
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

    parent.assign(n, 0);
    std::iota(parent.begin(), parent.end(), 0);
    vector<Point> stars(n);

    for (int i = 0; i < n; i++)
    {
        float x, y;
        cin >> x >> y;

        stars[i] = {x, y};
    }

    vector<Edge> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float distance = sqrt(pow(stars[i].x - stars[j].x, 2) + pow(stars[i].y - stars[j].y, 2));
            edges.push_back({i, j, distance});
        }
    }

    sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2)
    {
        return e1.w < e2.w;
    });

    int cnt = n - 1;
    int i = 0;

    float result = 0;
    while (cnt)
    {
        const Edge& e = edges[i];
        int p = e.v1;
        int q = e.v2;

        if (!Equal(p, q))
        {
            Union(p, q);
            result += e.w;
            cnt--;
        }
        i++;
    }

    cout << fixed;
    cout.precision(2);
    cout << result;


    return 0;
}