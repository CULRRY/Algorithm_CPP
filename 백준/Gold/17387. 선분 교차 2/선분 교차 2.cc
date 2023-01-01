#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace std;

using ll = long long;

struct Line
{
    ll x1, y1;
    ll x2, y2;
};

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll result = x1 * y2 + x2 * y3 + x3 * y1 - (y1 * x2 + y2 * x3 + y3 * x1);
    if (result > 0) return 1;
    else if (result < 0) return -1;
    else  return 0;
}

void Swap(Line& l)
{
    if (l.x1 == l.x2)
    {
        if (l.y1 >= l.y2)
        {
            ::swap(l.x1, l.x2);
            ::swap(l.y1, l.y2);
            return;
        }
    }
    
    if (l.x1 >= l.x2)
    {
        ::swap(l.x1, l.x2);
        ::swap(l.y1, l.y2);   
    }
}



int main()
{
    FASTIO;

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    Line l1 = {a, b, c, d};
    cin >> a >> b >> c >> d;
    Line l2 = {a, b, c, d};
    Swap(l1);

    ll normL1 = ccw(l1.x1, l1.y1, l1.x2, l1.y2, l2.x1, l2.y1) * ccw(l1.x1, l1.y1, l1.x2, l1.y2, l2.x2, l2.y2);
    ll normL2 = ccw(l2.x1, l2.y1, l2.x2, l2.y2, l1.x1, l1.y1) * ccw(l2.x1, l2.y1, l2.x2, l2.y2, l1.x2, l1.y2);
    if (normL1 <= 0)
    {
        if (normL1 == 0 && normL2 == 0)
        {
            Swap(l1); Swap(l2);
            if (l1.x1 == l2.x2 ? l1.y1 <= l2.y2 : l1.x1 <= l2.x2)
            {
                if (l2.x1 == l1.x2 ? l2.y1 <= l1.y2 : l2.x1 <= l1.x2)
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }
            else
            {
                cout << 0;
            }
        }
        else if (normL2 <= 0)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    else
    {
        cout << 0;
    }

    return 0;
}