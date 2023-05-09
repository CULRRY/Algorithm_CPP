#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"
using namespace std;

int n, l;
vector<vector<int>> heights;

bool solution(vector<int>& v)
{

    vector<bool> isUsed(n, false);
    for (int i = 0; i < n - 1; i++)
    {
        if (abs(v[i] - v[i + 1]) > 1)
            return false;

        if (v[i] > v[i + 1])
        {
            if (i + l >= n)
                return false;

            int norm = v[i + 1];

            for (int j = 0; j < l; j++)
            {
                if (v[i + j + 1] != norm)
                    return false;

                if (isUsed[i + j + 1] == true)
                    return false;
                
                isUsed[i + j + 1] = true;
            }
            
            
        }
        else if (v[i] < v[i + 1])
        {
            if (i - l + 1< 0)
                return false;

            int norm = v[i];

            for (int j = 0; j < l; j++)
            {
                if (v[i - j] != norm)
                    return false;

                if (isUsed[i - j] == true)
                    return false;
                
                isUsed[i - j] = true;
            }
        }
    }

    return true;
}

int main()
{
    FASTIO;

    cin >> n >> l;
    heights = vector<vector<int>>(n, vector<int>(n));

    for (auto& v : heights)
        for (auto& i : v)
            cin >> i;
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (solution(heights[i]))
            ans++;
        
        vector<int> tmp;
        for (int j = 0; j < n; j++)
        {
            tmp.push_back(heights[j][i]);
        }

        if (solution(tmp))
            ans++;
    }

    cout << ans << endl;

    return 0;
}