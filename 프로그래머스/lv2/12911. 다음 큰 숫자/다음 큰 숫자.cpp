#include <string>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

int count1(int n)
{
    int ret = 0;
    
    for (int i = 0; i <= 31; i++)
    {
        if ((n & 1 << i) == 1 << i)
            ret++;
    }
    
    return ret;
}

int solution(int n) {
    int answer = n+1;
    int origin = count1(n);
    while (true)
    {
        if (origin == count1(answer))
            break;
        
        answer++;
    }
    
    
    
    return answer;
}