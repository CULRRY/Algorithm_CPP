#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point
{
    ll x, y;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Point> points;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (points[i].x + points[(i+1) % n].x)*(points[i].y - points[(i+1) % n].y);
    }

    sum = abs(sum);
    long long result = sum / 2;
    cout << result;
    if (sum % 2 == 0)
    {
        cout <<".0";
    }
    else
        cout << ".5";

    return 0;
}