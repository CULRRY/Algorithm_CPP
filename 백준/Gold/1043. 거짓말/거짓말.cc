#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int Find(int x)
{
    if (x == v[x])
        return x;
    return v[x] = Find(v[x]);
}

void Union(int x, int y)
{
    int a = Find(x);
    int b = Find(y);
    v[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int k;
    cin >> k;
    v.assign(N+1, 0);
    for (int i = 1; i <= N; i++)
    {
        v[i] = i;
    }

    vector<int> knows;
    vector<vector<int>> party(M);
    while (k--)
    {
        int x;
        cin >> x;
        knows.push_back(x);
    }

    int prev, num;
    for (int i = 0; i < M; i++)
    {
        int p;
        cin >> p;
        for (int j = 0; j < p; j++)
        {
            if (j == 0)
            {
                cin >> num;
            }
            else
            {
                prev = num;
                cin >> num;
                Union(prev, num);
            }

            party[i].push_back(num);
        }
    }

    int cnt = M;
    for (auto& a : party)
    {
        bool flag = false;
        for (auto& b : a)
        {
            if (flag)
                break;

            for (auto& c : knows)
            {
                if (Find(c) == Find(b))
                {
                    flag = true;
                    break;
                }
            }
        }

        if (flag)
        {
            cnt--;
        }
    }

    cout << cnt << "\n";

    return 0;
}