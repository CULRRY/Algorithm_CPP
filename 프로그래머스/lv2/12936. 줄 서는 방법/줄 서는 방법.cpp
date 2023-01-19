#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long factorial(int n)
{
    long long temp = 1;
    for (int i = 2; i <= n; i++)
    {
        temp *= i;
    }
    
    return temp;
}

vector<int> solution(int n, long long k) {
    vector<int> answer(n);
    
    for (int i = 1; i <= n; i++)
    {
        answer[i-1] = i;
    }
    
    for (int i = 1; i <= n - 1; i++)
    {
        long long fact = factorial(n - i);
        
        int idx = i;
        while (k - fact > 0)
        {
            k -= fact;
            swap(answer[i - 1], answer[idx]);
            idx++;
        }
    }
    
    return answer;
}