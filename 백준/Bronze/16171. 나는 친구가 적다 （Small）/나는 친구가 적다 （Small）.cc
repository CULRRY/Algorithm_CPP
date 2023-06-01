#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    string Q, A;
    cin >> Q >> A;

    string tmp;
    for (char c : Q)
    {
        if (c >= '0' && c <= '9')
            continue;
        tmp.push_back(c);
    }

    if (tmp.find(A) == -1)
        cout << 0 << endl;
    else
        cout << 1 << endl;

    return 0;
}