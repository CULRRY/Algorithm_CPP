#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i += n)
    {
        cout << s[i];
    }


    return 0;
}