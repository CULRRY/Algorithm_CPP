#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
using ull = unsigned long long;

int main()
{
    FASTIO;

    ull n;
    cin >> n;

    string skcy[] = {"CY", "SK"};

    n %= 4UL;
    n %= 2UL;

    cout << skcy[n]; 

    return 0;
}