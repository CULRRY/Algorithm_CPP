#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;
using ll = long long;


struct Point
{
    ll y, x;
};

struct Line
{
    Point p1, p2;
};

vector<int> parent;
vector<int> weight;

int Find(int p)
{
    if (p == parent[p])
        return p;

    return parent[p] = Find(parent[p]);
}

void Union(int p, int q)
{
    p = Find(p);
    q = Find(q);
    if (weight[p] > weight[q])
    {
        parent[q] = p;
        weight[p] += weight[q];
    }
    else
    {
        parent[p] = q;
        weight[q] += weight[p];
    }
}

bool isEqual(int p, int q)
{
    return Find(p) == Find(q);
}

int ccw(Point p1, Point p2, Point p3)
{
    ll result = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
    if (result > 0)
        return 1;
    else if (result < 0)
        return -1;
    else
        return 0;
}

void Swap(Line& l)
{
    if (l.p1.x == l.p2.x)
    {
        if (l.p1.y > l.p2.y)
        {
            ::swap(l.p1, l.p2);
        }
    }
    else if (l.p1.x > l.p2.x)
    {
        ::swap(l.p1, l.p2);
    }
}

bool isCrossed(Line& l1, Line& l2)
{
    int ccwNormL1 = ccw(l1.p1, l1.p2, l2.p1) * ccw(l1.p1, l1.p2, l2.p2);
    int ccwNormL2 = ccw(l2.p1, l2.p2, l1.p1) * ccw(l2.p1, l2.p2, l1.p2);
    if (ccwNormL1 <= 0)
    {
        if (ccwNormL1 == 0 && ccwNormL2 == 0)
        {
            Swap(l1);
            Swap(l2);

            if (l1.p1.x == l2.p2.x ? l1.p1.y <= l2.p2.y : l1.p1.x <= l2.p2.x)
            {
                if (l1.p2.x == l2.p1.x ? l2.p1.y <= l1.p2.y : l2.p1.x <= l1.p2.x)
                {
                    return true;
                }
                return false;
            } 

            return false;
        }

        if (ccwNormL2 <= 0)
        {
            return true;
        }
    }
    else
        return false;
    
    return false;

}

int main()
{
    FASTIO;

    int n;
    cin >> n;
    vector<Line> lines(n);
    parent = vector<int>(n);
    weight = vector<int>(n, 1);
    std::iota(parent.begin(), parent.end(), 0);
    
    for (Line& line : lines)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        line = {{y1, x1}, {y2, x2}};
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isEqual(i, j))
                continue;
            if (isCrossed(lines[i], lines[j]))
            {
                Union(i, j);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
            cnt++;
    }
    cout << cnt << "\n";
    cout << *max_element(weight.begin(), weight.end());
    return 0;
}