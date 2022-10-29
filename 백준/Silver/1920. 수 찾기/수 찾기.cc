#include <bits/stdc++.h>
using namespace std;
int search(vector<int>& v, int left, int right, int value)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        

        if (v[mid] == value)
            return 1;

        else if (v[mid] > value)
        {
            right = mid - 1;
            continue;
        }
        else
        {
            left = mid + 1;
            continue;
        }    
    }

    return 0;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int M;
    cin >> M;
    
    for (int i = 0; i < M; i++)
    {
        int t;
        cin >> t;
        cout << search(v, 0, N-1, t) << "\n";
    }


    return 0;
}