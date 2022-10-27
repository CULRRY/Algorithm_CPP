#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    int count = 0;
    int i = 666;
    while (true)
    {
        int tmp = i;
        while (tmp != 0)
        {
            if (tmp % 1000 == 666)
            {
                count++;
                break;
            }
            tmp /= 10;
        }
        if (N == count)
            break;

        i++;
    }

    cout << i << "\n";

    return 0;
}