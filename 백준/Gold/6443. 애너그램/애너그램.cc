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

    while (n--)
    {
        string s;
        cin >> s;
        std::sort(s.begin(), s.end());
        cout << s << endl;
        while (next_permutation(s.begin(), s.end()))
        {
            cout << s << endl;
        }
    }
    

    return 0;
}