#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    string s;
    cin >> s;

    vector<int> cnt(9, 0);

    string year = "2018";
    bool flag = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (year.find(s[i]) == EOF)
        {
            flag = true;
            break;
        }

        cnt[s[i] - '0']++;
    }

    if (flag)
        cout << 0;
    else
    {
        int isBind = true;
        int norm = cnt[2];
        for (char c : year)
        {
            if (cnt[c - '0'] == 0)
            {
                cout << 1;
                return 0;
            }
            if (norm != cnt[c - '0'])
                isBind = false;
        }

        if (isBind)
            cout << 8;
        else
            cout << 2;
    }

    return 0;
}