#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    FASTIO;

    string name;
    cin >> name;
    sort(name.begin(), name.end());
    string ans;
    ans.resize(name.size());
    int left = 0;
    int right = name.size() - 1;
    int idx = 0;
    char key = 'x';
    while (left <= right)
    {
        if (left == right)
        {
            if (idx == name.size() - 1)
            {
                ans[left] = name[idx];
            }
            else
            {
                ans[left] = key;
            }
            break;
        }
        if (name[idx] == name[idx + 1])
        {
            ans[left] = ans[right] = name[idx];
            left++;
            right--;
            idx += 2;
        }
        else
        {
            if (key == 'x')
            {
                key = name[idx];
                idx++;
            }
            else
            {
                ans = "I'm Sorry Hansoo";
                break;
            }
        }
    }
    cout << ans;

    return 0;
}