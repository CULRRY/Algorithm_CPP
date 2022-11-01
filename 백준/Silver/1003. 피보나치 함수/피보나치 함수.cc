#include <bits/stdc++.h>
using namespace std;

int memo0[41] = {0,};
int memo1[41] = {0,};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i< N ; i++)
    {
        int a;
        cin >> a;
        for (int i = 0; i <= a; i++)
        {
            if (i == 0)
            {
                memo0[i] = 1;
            }
            else if (i == 1)
            {
                memo1[i] = 1;
            }
            else
            {
                memo0[i] = memo0[i - 1] + memo0[i - 2];
                memo1[i] = memo1[i - 1] + memo1[i - 2];
            }
        }
        cout << memo0[a] << " " << memo1[a] << "\n";
    }

    return 0;
}