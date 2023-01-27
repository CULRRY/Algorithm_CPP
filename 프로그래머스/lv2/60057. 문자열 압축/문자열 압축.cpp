#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 98765542;
    
    for (int i = 1; i <= s.size(); i++)
    {
        string tmp = "";
        string prev = s.substr(0, i);
        int cnt = 1;
        for (int j = i; j < s.size(); j += i)
        {
            if (s.substr(j, i) == prev)
                cnt++;
            else
            {
                if (cnt >= 2)
                {
                    tmp += to_string(cnt) + prev;
                }
                else
                {
                    tmp += prev;
                }
                cnt = 1;
            }
            prev = s.substr(j, i);
        }
        if (cnt >= 2)
        {
            tmp += to_string(cnt) + prev;
        }
        else
        {
            tmp += prev;
        }
        answer = min((int)tmp.size(), answer);
        
    }
    
    return answer;
}