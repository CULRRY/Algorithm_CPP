#include <bits/stdc++.h>
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define endl "\n"

using namespace std;

int k;
vector<int> arr;
vector<vector<int>> ans;

void solution(int left, int right, int depth)
{
    if (left > right)
        return;

    int mid = (left + right) / 2;
    ans[depth].push_back(arr[mid]);


    solution(left, mid - 1, depth + 1);
    solution(mid + 1, right, depth + 1);
}

int main()
{
    FASTIO;

    cin >> k;
    arr = vector<int>((int)pow(2, k) - 1);
    for (int& i : arr)
        cin >> i;
    ans = vector<vector<int>>(k);
    solution(0, arr.size() - 1, 0);

    for (vector<int>& v : ans)
    {
        for (int& i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}