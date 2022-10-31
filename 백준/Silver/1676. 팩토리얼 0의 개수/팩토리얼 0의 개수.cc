#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    long long num = 1;
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        num = (num * i)%1000000000;
        long long tmp = num;
        int numOfZero = 0;
        while (tmp != 0)
        {
            if (tmp % 10 == 0)
            {
                count++;
                numOfZero++;
            }
            else
            {
                break;
            }
            tmp /= 10;
        }
        
        if (numOfZero != 0)
            num /= (int)pow(10, numOfZero);
        

    }

    cout << count;

    return 0;
}