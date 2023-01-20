#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    int answer = 1;
    stack<char> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (stk.empty())
        {
            stk.push(s[i]);
            continue;
        }
            
        
        if (stk.top() == s[i])
        {
            stk.pop();
        }
        else
        {
            stk.push(s[i]);
        }
        
    }
    
    if (!stk.empty())
    {
        answer = 0;
    }
    
    return answer;
}