#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    unordered_map<string, float> grade;
    grade["A+"] = 4.3;
    grade["A0"] = 4.0;
    grade["A-"] = 3.7;
    grade["B+"] = 3.3;
    grade["B0"] = 3.0;
    grade["B-"] = 2.7;
    grade["C+"] = 2.3;
    grade["C0"] = 2.0;
    grade["C-"] = 1.7;
    grade["D+"] = 1.3;
    grade["D0"] = 1.0;
    grade["D-"] = 0.7;
    grade["F"] = 0.0;

    string n;
    cin >> n;

    cout << fixed;
    cout.precision(1);
    cout << grade[n] << endl;

    return 0;
}