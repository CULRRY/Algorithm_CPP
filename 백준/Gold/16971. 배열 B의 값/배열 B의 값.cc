#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;
int n, m;
int origin = 0;
vector<int> accumRow;
vector<int> accumCol;


int SwapRow(int r)
{
    int tmp = -987654432;
    tmp = std::max(tmp, origin - accumRow[r]/2 + accumRow[1]);
    tmp = std::max(tmp, origin - accumRow[r]/2 + accumRow[n]);

    return tmp;
}

int SwapCol(int c)
{
    int tmp = -987654432;
    tmp = std::max(tmp, origin - accumCol[c]/2 + accumCol[1]);
    tmp = std::max(tmp, origin - accumCol[c]/2 + accumCol[m]);

    return tmp;
}


int main()
{
    FASTIO;

    cin >> n >> m;
    accumRow.assign(n+1, 0);
    accumCol.assign(m+1, 0);



    /*
    1 2 2 2 1
    2 4 4 4 2
    2 4 4 4 2
    2 4 4 4 2
    1 2 2 2 1
    */




    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int v;
            cin >> v;
            
            if ((i == n || i == 1) && (j == m || j == 1))
            {
                origin += v;
                accumRow[i] += v;
                accumCol[j] += v;
            }
            else if ((i == n || i == 1) || (j == m || j == 1))
            {
                origin += 2*v;
                accumRow[i] += 2*v;
                accumCol[j] += 2*v;
            }
            else
            {
                origin += 4*v;
                accumRow[i] += 4*v;
                accumCol[j] += 4*v;
            }

        }
    }

    
    int max = origin;

    for (int i = 2; i < n; i++)
    {
        max = std::max(max, SwapRow(i));
    }

    for (int i = 2; i < m; i++)
    {
        max = std::max(max, SwapCol(i));
    }

    cout << max;

    return 0;
}