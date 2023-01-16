#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
int n, m, r;

void Rotate(vector<vector<int>>& v, int r)
{
    int check = min(n, m) / 2;
    vector<vector<int>> tmp;
    for (int cnt = 0; cnt < check; cnt++)
    {
        int ys = cnt;
        int xs = cnt;
        int ye = n - cnt - 1;
        int xe = m - cnt - 1;
        vector<int> t;

        for (int i = ys; i <= ye; i++)
        {
            t.push_back(v[i][xs]);
        }
        for (int i = xs + 1; i <= xe; i++)
        {
            t.push_back(v[ye][i]);
        }
        for (int i = ye - 1; i >= ys; i--)
        {
            t.push_back(v[i][xe]);
        }
        for (int i = xe - 1; i >= xs + 1; i--)
        {
            t.push_back(v[ys][i]);
        }
        tmp.push_back(t);
    }
    
    int ys = 0;
    int xs = 0;
    int ye = n - 1;
    int xe = m - 1;

    for (int c = 0; c < tmp.size(); c++)
    {
        int tm = tmp[c][0];
        int size = tmp[c].size();
        vector<int> cm(tmp[c]);
        for (int z = 0; z < size; z++)
        {
            cm[(z + r) % size] = tmp[c][z];
        }
        int idx = 0;
        for (int i = ys; i <= ye; i++)
        {
            v[i][xs] = cm[idx++];
        }
        for (int i = xs + 1; i <= xe; i++)
        {
            v[ye][i] = cm[idx++];
        }
        for (int i = ye - 1; i >= ys; i--)
        {
            v[i][xe] = cm[idx++];
        }
        for (int i = xe - 1; i >= xs + 1; i--)
        {
            v[ys][i] = cm[idx++];
        }
        ys++;
        ye--;
        xs++;
        xe--;
    }




}

int main()
{
    FASTIO;
    cin >> n >> m >> r;

    vector<vector<int>> v(n, vector<int>(m, 0));

    for (auto& t : v)
    {
        for (auto& i : t)
        {
            cin >> i;
        }
    }

    Rotate(v, r);

    for (auto& t : v)
    {
        for (auto& i : t)
        {
            cout << i << " ";
        }
        cout << endl;
    }



    return 0;
}