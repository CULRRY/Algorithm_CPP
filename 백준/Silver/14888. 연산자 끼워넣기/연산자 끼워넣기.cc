#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n;
vector<int> a;
array<int, 4> opers;

int maxValue = INT_MIN, minValue = INT_MAX;

enum
{
    PLUS, MINUS, MUL, DIV
};

int calculate(int v1, int v2, int oper)
{
    switch (oper)
    {
    case PLUS:
        return v1 + v2;
    case MINUS:
        return v1 - v2;
    case MUL:
        return v1 * v2;
    case DIV:
        return v1 / v2;
    default:
        break;
    }
    
    return 0;
}

void bt(int idx, int result)
{

    if (idx >= n)
    {
        maxValue = std::max(result, maxValue);
        minValue = std::min(result, minValue);
        return;
    }

    for (int op = PLUS; op <= DIV; op++)
    {
        if (opers[op] <= 0)
            continue;
        
        opers[op]--;
        bt(idx + 1, calculate(result, a[idx], op));
        opers[op]++;
    }
}

int main()
{
    FASTIO;

    cin >> n;
    a = vector<int>(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < 4; i++)
        cin >> opers[i];

    bt(1, a[0]);

    cout << maxValue << endl << minValue << endl;

    return 0;
}