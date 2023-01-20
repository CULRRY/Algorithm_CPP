#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    int round = 1;
    a = (a + 1) / 2;
    b = (b + 1) / 2;
    
    while (a != b)
    {
        a = (a+1) / 2;
        b = (b+1) / 2;
        round++;
    }

    answer = round;
    return answer;
}