#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int n;

vector<int> arr;

void NQueen(int d)
{

    for (int i = 1; i < d; i++)
    {
        if (arr[i] == arr[d] || abs(d - i) == abs(arr[d] - arr[i]))
            return;
    }

    if (d == n)
    {
        cnt++;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        arr[d+1] = i;
        NQueen(d+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    arr.assign(n + 1, 0);

    NQueen(0);

    cout << cnt << "\n";

    return 0;
}