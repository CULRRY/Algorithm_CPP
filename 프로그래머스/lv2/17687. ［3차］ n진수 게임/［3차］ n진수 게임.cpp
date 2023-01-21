#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string BaseConversion(int n, int base)
{
    static string baseTable = "0123456789ABCDEF";
    stack<char> s;
    
    s.push(baseTable[n % base]);
    n/= base;
    while (n >= 1)
    {
        s.push(baseTable[n % base]);
        n /= base;
    }
    
    string ret = "";
    
    while(!s.empty())
    {
        ret += s.top();
        s.pop();
    }
    return ret;
    
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string tmp = "";
    for (int i = 0; i < t*m; i++)
    {
        tmp += BaseConversion(i, n);
    }
    int cnt = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if ((i % m) + 1 == p)
        {
            answer += tmp[i];
            cnt++;
            if (cnt == t)
                break;
        }
            
    }
    
    return answer;
}