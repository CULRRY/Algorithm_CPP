#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = v[i];
        if (sum > M)
            continue;
        for (int j = i + 1; j < N; j++)
        {
            int sum = v[i] + v[j];
            if (sum > M)
                continue;
            for (int k = j + 1; k < N; k++)
            {
                int sum = v[i] + v[j] + v[k];
                if (sum > M)
                    continue;

                if (sum > max)
                    max = sum;
            }
        }
    }

    cout << max;

    return 0;
}