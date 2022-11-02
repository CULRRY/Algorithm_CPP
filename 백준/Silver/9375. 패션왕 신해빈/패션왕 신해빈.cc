#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        map<string, int> m;
        for (int j = 0; j < n; j++)
        {
            string s1 = "", s2 = "";
            cin >> s1 >> s2;
            auto it = m.find(s2);
            if (it == m.end())
            {
                m[s2] = 1;
            }
            else
            {
                m[s2]++;
            }
        }
        int total = 1;

        for (auto i : m)
        {
            total *= i.second + 1;
        }


        cout << total - 1 << "\n";
    }

    return 0;
}