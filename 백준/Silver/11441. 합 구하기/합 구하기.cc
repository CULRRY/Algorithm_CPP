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

    vector<int> arr;

    int sum = 0;
    arr.push_back(sum);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        arr.push_back(sum);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int start, end;

        cin >> start >> end;

        cout << arr[end] - arr[start - 1] << endl;

    }

    return 0;
}