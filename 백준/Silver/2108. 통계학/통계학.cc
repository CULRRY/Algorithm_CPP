#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    //산술평균
    sort(v.begin(), v.end());
    double sum = 0.0;
    for (int i : v)
    {
        sum += static_cast<double>(i);
    }

    int mean = round(sum / static_cast<double>(N));
    cout << mean << "\n";

    //중앙값
    cout << v[(v.size() - 1) / 2] << "\n";

    //최빈값
    vector<int> freq(8001, 0);

    for (int i = 0; i < N; i++)
    {
        freq[4000 + v[i]]++;
    }
    
    int max = 0;
    int idx = 0;
    int count = 0;
    for (int i = 8000; i >= 0; i--)
    {
        if (freq[i] >= max)
        {
            max = freq[i];
            idx = i;
        }
    }

    int a = freq[3999];
    for (int i = idx; i <= 8000; i++)
    {
        if (freq[i] == max)
        {
            count++;
            if (count == 2)
            {
                idx = i;
                break;
            }
        }
    }

    cout << idx - 4000 << "\n";

    //범위
    cout << v.back() - v.front() << "\n";
    return 0;
}