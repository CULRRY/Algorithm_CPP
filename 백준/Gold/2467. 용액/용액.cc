#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> solutions(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> solutions[i];
    }

    int left = 1;
    int right = n;
    int min = INT_MAX;
    int m1, m2;
    while (left < right)
    {
        int mid = (left + right) / 2;
        int sol = solutions[left] + solutions[right];
        int absol = abs(solutions[left] + solutions[right]);
        if (min > absol)
        {
            min = absol;
            m1 = left;
            m2 = right;
        }

        if (sol == 0)
            break;

        if (sol < 0)
        {
            left = left+1;
            continue;
        }

        if (sol > 0)
        {
            right = right-1;
            continue;
        }


    }

    cout << solutions[m1] << " " << solutions[m2];


    return 0;
}