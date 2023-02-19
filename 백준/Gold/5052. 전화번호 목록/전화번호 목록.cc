#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> numbers(n);
        for (int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }

        sort(numbers.begin(), numbers.end());
        bool ans = true;
        for (int i = 0; i < n - 1; i++)
        {
            int idx = numbers[i+1].find(numbers[i]);
            if (idx != -1)
            {
                if (idx != 0)
                    continue;
                ans = false;
                break;
            }
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    

    return 0;
}