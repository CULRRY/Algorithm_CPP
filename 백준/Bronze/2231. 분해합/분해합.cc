#include<iostream>
using namespace std;


int decompose(int n)
{
    int sum = n;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}


int main()
{
    int N;
    cin >> N;

    for (int i = 1; i < N; i++)
    {
        int decom = decompose(i);
        if (decom == N)
        {
            cout << i;
            return 0;
        }     
    }

    cout << 0;
    return 0;
}