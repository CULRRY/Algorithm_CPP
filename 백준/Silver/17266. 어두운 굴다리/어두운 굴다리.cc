#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;
    vector<int> b(m, 0);

    for (int& i : b)
    {
        cin >> i;
    }

    int left = 1;
    int right = n;
    int min = INT_MAX;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        int h = mid;
        int lightCnt = 0;
        vector<bool> isLight(n + 1, false);

        bool flag = false;
        int prevRange = 0;
        for (int idx : b)
        {
            if (idx - h > prevRange)
            {
                flag = true;
                break;
            }

            prevRange = idx + h;
        }
        
        if (prevRange < n)
            flag = true;

        if (flag)
        {
            left = mid + 1;
        }
        else
        {
            min = std::min(min, h);
            right = mid - 1;
        }

    }
    
    cout << min << endl;

    return 0;
}