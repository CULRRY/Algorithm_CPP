#include <bits/stdc++.h>
using namespace std;

int M, N;
vector<int> v;
vector<int> arr;

void print(int d, int s)
{
    if (d == M)
    {
        for (int a : arr)
        {
            cout << a << " ";
        }

        cout << "\n";

        return;
    }

    int tmp = 0;
    for (int i = s; i < N; i++)
    {

        if (i > 0 && tmp == v[i])
            continue;

        tmp = v[i];
        arr[d] = v[i];
        print(d + 1, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    v.assign(N, 0);
    arr.assign(M, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    print(0, 0);

    return 0;
}