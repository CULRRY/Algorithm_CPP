#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

bool Check(string s)
{
    stack<char> stk;
    for (char& c : s)
    {
        if (c == '{')
            stk.push('}');
        else if (c == '[')
            stk.push(']');
        else if (c == '(')
            stk.push(')');
        else
        {
            if (stk.empty())
                return false;
            
            if (c != stk.top())
                return false;
            
            stk.pop();
        }
    }
    if (!stk.empty())
        return false;
    
    return true;
}

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.size(); i++)
    {
        char tmp = s[0];
        for (int j = 0; j < s.size()-1; j++)
        {
            s[j] = s[j+1];
        }
        s.back() = tmp;
        if (Check(s))
            answer++;
    }
    return answer;
}