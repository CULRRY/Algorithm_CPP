#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &v, int t)
{
    int left = 0;
    int right = v.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (v[mid] == t)
            return mid;
        else if (v[mid] > t)
        {
            right = mid;
        }
        else
            left = mid + 1;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v;
    while (N--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    vector<int> sorted(v.begin(), v.end());
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    for (int i = 0; i < v.size(); i++)
    {
        int idx = binarySearch(sorted, v[i]);
        cout << idx << " ";

    }

    return 0;
}