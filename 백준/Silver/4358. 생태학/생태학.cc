#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    map<string, int> m;


    int cnt = 0;
    string s;
    while (getline(cin, s))
    {
        m[s]++;
        cnt++;
    }

    cout << fixed;
    cout.precision(4);
    for (auto item : m)
    {
        double ratio = ((double)item.second / (double)cnt) * 100;
        cout << item.first << " " << ratio << endl;
    }
    

    return 0;
}