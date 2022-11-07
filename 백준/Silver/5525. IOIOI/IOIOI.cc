#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int N, M;
    cin >> N >> M >> s;
    int idx = 0;
    int result = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int count = 0;
        if (s[i] == 'I')
        {
            for (int j = i + 1; j < s.size(); j += 2)
            {
                if (s[j] == 'O' && s[j + 1] == 'I')
                {
                    count++;
                }
                else
                {
                    i = j - 1;
                    break;
                }
            }
        }

        if (count >= N)
        {
            result += count - (N - 1);
        }
    }

    cout << result;
    return 0;
}