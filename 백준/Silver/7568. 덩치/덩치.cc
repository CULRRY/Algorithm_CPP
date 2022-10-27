#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> weight(n);
    vector<int> height(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> height[i];
    }

    for (int i = 0; i < n; i++)
    {
        int rank = 1;
        for (int j = 0; j < n; j++)
        {
            if (height[j] > height[i] && weight[j] > weight[i])
                rank++;
        }
        cout << rank << " ";
    }

    return 0;
}