#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
    int size = end - begin + 1;
    vector<int> answer(size);
    
    for (int i = begin; i <= end; i++)
    {
        if (i == 1)
        {
            answer[i - begin] = 0;
            continue;
        }
        
        int n = 1;
        for (int j = 2; j <= sqrt(i) ; j++)
        {
            
            if (i % j == 0 && i / j <= 10000000)
            {
                n = j;
                break;
            }
        }
        if (n == 1)
            answer[i - begin] = 1;
        else
            answer[i - begin] = i / n;
    }
    
    return answer;
}