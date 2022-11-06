#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> v;
    while (N--)
    {
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }
    sort(v.begin(), v.end(), [](pair<int, int>& p1, pair<int,int>& p2)
    {
        if (p1.second == p2.second)
        {
            if (p1.first > p2.first)
            {
                return false;
            }
            else
                return true;
        }
        if(p1.second > p2.second)
        {
            return false;
        }
        else
            return true;
    });

    int norm = v[0].second;
    int count = 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (norm > v[i].first)
            continue;
        
        norm = v[i].second;
        count++;
    }
    cout << count;
    return 0;
}
