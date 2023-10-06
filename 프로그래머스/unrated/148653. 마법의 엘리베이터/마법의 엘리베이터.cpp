#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    int now = storey;
    int div = 10;
    while (now  != 0)
    {
        int n = now % (div);
        now /= div;
        
        int next = now % div;
        
        if (next >= 5)
        {
            if (n >= 5)
            {
                answer += 10 - n;
                now++;
            }
            else
            {
                answer += n;
            }
        }
        else
        {
            if (n > 5)
            {
                answer += 10 - n;
                now++;
            }
            else
            {
                answer += n;
            }
        }
        
        
    }
    
    return answer;
}