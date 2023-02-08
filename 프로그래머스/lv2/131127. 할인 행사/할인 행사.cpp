#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    unordered_map<string, int> wants;
    
    for (int i = 0; i < want.size(); i++)
    {
        wants[want[i]] = number[i];
    }
    
    for (int i = 0; i < discount.size(); i++)
    {
        unordered_map<string, int> tmp;
        for (int j = i; j < i + 10 && j < discount.size(); j++)
        {
            tmp[discount[j]]++;
        }
        bool flag = true;
        
        for (auto item : wants)
        {
            auto it = tmp.find(item.first);
            if (it == tmp.end())
            {
                flag = false;
                break;
            }
            else
            {
                if (it->second < item.second)
                {
                    flag = false;
                    break;
                }
            }
        }
        
        if (flag)
            answer++;
    }
    
    
    
    return answer;
}