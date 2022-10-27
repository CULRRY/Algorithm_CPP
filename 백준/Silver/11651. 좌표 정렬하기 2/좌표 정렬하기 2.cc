#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        v.push_back(pair<int, int>(x, y));
    }

    sort(v.begin(), v.end(),
         [](pair<int, int> p1, pair<int, int> p2)
         {
             if (p1.second == p2.second)
                 return p1.first < p2.first;
             return p1.second < p2.second;
         });

    for (int i = 0; i < N; i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}