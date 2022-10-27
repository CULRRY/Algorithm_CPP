#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, string>> v;
    int N;
    cin >> N;
    for (int i = 0; i < N; i ++)
    {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(pair<int, string>(age, name));
    }

    stable_sort(v.begin(), v.end(), [](pair<int, string> p1, pair<int, string> p2)
                { return p1.first < p2.first; });

    for (int i = 0; i < N; i++)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}