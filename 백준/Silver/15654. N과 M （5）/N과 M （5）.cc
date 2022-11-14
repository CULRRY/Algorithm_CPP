#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> v;
vector<bool> canUse;
vector<int> result;

void print(int d, int start)
{
    if (d == M)
    {
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";

        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (canUse[i])
        {
            canUse[i] = false;
            result[d] = v[i];
            print(d + 1, start + 1);
            canUse[i] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    v.assign(N, 0);
    result.assign(M, 0);
    canUse.assign(N, true);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    print(0, 0);

    return 0;
}