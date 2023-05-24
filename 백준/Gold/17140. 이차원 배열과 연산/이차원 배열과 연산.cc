#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

struct Number
{
    int n, t;
};

vector<vector<int>> a(101, vector<int>(101, 0));
int rn = 3;
int cn = 3;
int r, c, k;

void R()
{
    for (int i = 1; i <= 100; i++)
    {
        int cnt[101] = {
            0,
        };
        vector<int> tmp(101, 0);
        for (int j = 1; j <= 100; j++)
        {
            if (a[i][j] == 0)
                continue;
            cnt[a[i][j]]++;
        }

        vector<Number> nums;
        for (int j = 1; j <= 100; j++)
        {
            if (cnt[j] == 0)
                continue;

            nums.push_back({j, cnt[j]});
        }

        std::sort
        (
            nums.begin(), nums.end(), [](const Number &n1, const Number &n2) 
            {
                if (n1.t == n2.t)
                    return n1.n < n2.n;
                return n1.t < n2.t;
            }
        );

        int cc = 0;

        for (int k = 1, l = 0; k <= 100 && l < nums.size(); k += 2, l++)
        {
            tmp[k] = nums[l].n;
            tmp[k+1] = nums[l].t;
            cc += 2;
        }

        a[i] = tmp;
        cn = std::max(cn, cc);
    }
}

void C()
{
    for (int i = 1; i <= 100; i++)
    {
        int cnt[101] = {
            0,
        };
        vector<int> tmp(101, 0);
        for (int j = 1; j <= 100; j++)
        {
            if (a[j][i] == 0)
                continue;
            cnt[a[j][i]]++;
        }

        vector<Number> nums;
        for (int j = 1; j <= 100; j++)
        {
            if (cnt[j] == 0)
                continue;

            nums.push_back({j, cnt[j]});
        }

        std::sort(
            nums.begin(), nums.end(), [](const Number &n1, const Number &n2)
            {
                if (n1.t == n2.t)
                    return n1.n < n2.n;
                return n1.t < n2.t; });

        int rc = 0;

        for (int k = 1, l = 0; k <= 100 && l < nums.size(); k += 2, l++)
        {
            tmp[k] = nums[l].n;
            tmp[k + 1] = nums[l].t;
            rc += 2;
        }

        for (int k = 1; k <= 100; k++)
        {
            a[k][i] = tmp[k];
        }

        rn = std::max(rn, rc);
    }
}

void go()
{
    if (rn >= cn)
    {
        R();
    }
    else
    {
        C();
    }
}

int main()
{
    FASTIO;

    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> a[i][j];
        }
    }
    int t = 0;

    while (a[r][c] != k)
    {
        t++;
        if (t == 101)
        {
            t = -1;
            break;
        }
        go();

    }

    cout << t << endl;
    return 0;
}