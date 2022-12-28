#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

struct Point
{
    int y, x;
};

double minVal;

void getMin(int depth, int plusCount, int minusCount, int n, vector<Point> p, Point sum)
{
    if (depth == n)
    {
        minVal = std::min(minVal, sqrt(pow(sum.y, 2) + pow(sum.x, 2)));
        return;
    }

    if (plusCount < n / 2)
        getMin(depth + 1, plusCount + 1, minusCount, n, p, {sum.y + p[depth + 1].y, sum.x + p[depth + 1].x});
    
    if (minusCount < n / 2)
        getMin(depth + 1, plusCount, minusCount + 1, n, p, {sum.y - p[depth + 1].y, sum.x - p[depth + 1].x});



}

int main()
{
    FASTIO;

    int tc;
    cin >> tc;
    while (tc--)
    {
        minVal = INT64_MAX;
        int n;
        cin >> n;
        vector<Point> p(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i].y >> p[i].x;
        
        getMin(1, 1, 0, n, p, {p[1].y, p[1].x});
        getMin(1, 0, 1, n, p, {-p[1].y, -p[1].x});

        cout << fixed;
        cout.precision(6);
        cout << minVal << "\n";
    }       
    return 0;
}