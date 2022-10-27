#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int a, b, v, now = 0, days = 0;
    cin >> a >> b >> v;

    days = (v - a) / (a - b);
    now = (a - b) * days;
    while(true)
    {
        days++;
        now += a;
        if (now >= v)
            break;
        now -= b;
    }

    cout << days << "\n";

    return 0;
}