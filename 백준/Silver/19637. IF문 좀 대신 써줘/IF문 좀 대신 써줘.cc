#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;
map<int, string> dict;
vector<int> range;


int main()
{
    FASTIO;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string word;
        int value;
        cin >> word >> value;

        if (dict.find(value) == dict.end())
        {
            dict[value] = word;
        }
    }



    for (auto item : dict)
    {
        range.push_back(item.first);
    }

    while (m--)
    {
        int input;
        cin >> input;

        int ans = *std::lower_bound(range.begin(), range.end(), input);

        cout << dict[ans] << endl;

    }
    

    return 0;
}