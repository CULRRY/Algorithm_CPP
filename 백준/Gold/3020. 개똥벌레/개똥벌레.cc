#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int main()
{
    FASTIO;

    int n, h;
    cin >> n >> h;

    vector<int> top(h + 1, 0);
    vector<int> bottom(h + 1, 0);
    vector<int> result(h + 1, 0);

    for (int i = 0; i < n / 2; i++)
    {
        int a, b;
        cin >> a >> b;
        bottom[a]++;
        top[h - b + 1]++;
    }

    for (int i = 1; i <= h; i++)
    {
        top[i] += top[i-1];
        bottom[h - i] += bottom[h - i + 1];
    }

    for (int i = 1; i <= h; i++)
    {
        result[i] = bottom[i] + top[i];
    }
    sort(result.begin(), result.end());

    int cnt = 1;

    for (int i = 2; i <= h; i++)
    {
        if (result[i] == result[1])
            cnt++;
        else
            break;
    }

    cout << result[1] << " " << cnt << endl;

    return 0;
}