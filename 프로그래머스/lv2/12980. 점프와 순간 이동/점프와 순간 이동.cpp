#include <iostream>
#include <algorithm>
using namespace std;

int minimum = 2000000000;


int solution(int n)
{
    int ans = 0;
    while (n != 0)
    {
        if (n % 2 == 1)
        {
            n -= 1;
            ans += 1;
        }
        else
        {
            n /= 2;
        }
    }

    return ans;
}