#include <string>
#include <vector>
#include <stack>

using namespace std;

string gen(string p)
{
    if (p == "")
        return "";
    int a = 0, b = 0;
    string u = "";
    bool correct = true;
    stack<char> s;
    for (char c : p)
    {
        if (c == '(')
        {
            a++;
            s.push('(');
        }
            
        else if (c == ')')
        {
            b++;
            if (s.empty())
            {
                correct = false;
            }
            else
            {
                s.pop();
            }
        }
        
        u += c;
        if (a == b)
            break;
    }
    string v = p.substr(a + b, p.size() - (a + b));
    if (correct)
    {
        return  u + gen(v);
    }
    else
    {
        string ret = "(" + gen(v) + ")";
        for (int i = 1; i < u.size() - 1; i++)
        {
            if (u[i] == '(')
                ret += ")";
            else
                ret += "(";
        }
        
        return ret;
    }
    
}

string solution(string p) {
    string answer = "";
    answer = gen(p);
    
    return answer;
}