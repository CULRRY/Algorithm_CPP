#include <bits/stdc++.h>
using namespace std;
int n;
unsigned long long b;

vector<vector<int>> matmul(const vector<vector<int>>& m1, const vector<vector<int>>& m2)
{

    vector<vector<int>> tmp(n, vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            long long cnt = 0;
            for (int k = 0; k < n; k++)
            {
                cnt += ((m1[i][k] % 1000) * (m2[k][j] % 1000)) % 1000;
            }
            tmp[i][j] = cnt % 1000;
        }
    }

    return tmp;
}

vector<vector<int>> PowerMatrix(vector<vector<int>> mat, unsigned long long b)
{
    if (b == 1)
    {
        return mat;
    }
    else if (b % 2 == 0)
    {
        vector<vector<int>> tmp = PowerMatrix(mat, b / 2);
        return matmul(tmp, tmp);
    }
    else
    {
        vector<vector<int>> tmp = PowerMatrix(mat, (b-1) / 2);
        tmp = matmul(tmp, tmp);
        return matmul(tmp, mat);
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> b;

    vector<vector<int>> m(n, vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    m = PowerMatrix(m, b);
    for (auto v : m)
    {
        for (auto o : v)
        {
            cout << o % 1000 << " ";
        }
        cout << "\n";
    }

    return 0;
}