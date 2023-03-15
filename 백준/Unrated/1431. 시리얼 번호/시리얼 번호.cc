#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n;

int main()
{
    FASTIO;

    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), [](string& a, string& b)
    {
        if (a.length() == b.length())
        {
            int suma = 0;
            int sumb = 0;

            for (char c : a)
            {
                if (c >= '0' && c <= '9')
                    suma += c - '0';
            }

            for (char c : b)
            {
                if (c >= '0' && c <= '9')
                    sumb += c - '0';
            }

            if (suma == sumb)
            {
                return a < b;
            }

            return suma < sumb;
        }
        return a.length() < b.length();
    });

    for (string s : v)
        cout << s << endl;

    return 0;
}