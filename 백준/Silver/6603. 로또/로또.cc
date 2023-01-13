#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0);
#define endl "\n"

using namespace std;

void bt(vector<int>& nums, int depth, int index, vector<int>& result)
{
    if (depth == 5)
    {
        for (int i : result)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    for (int i = index + 1; i < nums.size(); i++)
    {
        result[depth + 1] = nums[i];
        bt(nums, depth + 1, i, result);
    }
}

int main()
{
    FASTIO;

    int k;
    while (true)
    {
        cin >> k;
        if (k == 0)
            break;
        
        vector<int> nums(k);
        vector<int> result(6);
        for (int i = 0; i < k; i++)
        {
            cin >> nums[i];
        }

        bt(nums, -1, -1, result);
        cout << endl;
    }
    

    return 0;
}