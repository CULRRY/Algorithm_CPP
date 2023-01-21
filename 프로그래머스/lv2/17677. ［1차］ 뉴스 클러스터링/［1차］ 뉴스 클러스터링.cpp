#include <string>
#include <cctype>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    for (char& c : str1)
    {
        c = toupper(c);
    }
    
    for (char& c : str2)
    {
        c = toupper(c);
    }
    unordered_map<string, int> str1m;
    unordered_map<string, int> str2m;

    for (int i = 0; i < str1.size()-1; i++)
    {
        string tmp = str1.substr(i, 2);
        if (tmp[0] > 'Z' || tmp[0] < 'A')
            continue;
        if (tmp[1] > 'Z' || tmp[1] < 'A')
            continue;
        if (str1m.find(tmp) == str1m.end())
        {
            str1m[tmp] = 1;
        }
        else
        {
            str1m[tmp] += 1;
        }
    }
    
    for (int i = 0; i < str2.size() - 1; i++)
    {
        string tmp = str2.substr(i, 2);
        if (tmp[0] > 'Z' || tmp[0] < 'A')
            continue;
        if (tmp[1] > 'Z' || tmp[1] < 'A')
            continue;
        if (str2m.find(tmp) == str2m.end())
        {
            str2m[tmp] = 1;
        }
        else
        {
            str2m[tmp] += 1;
        }
    }
    
    int cross = 0;
    int uni = 0;
    for (auto item : str1m)
    {
        auto it = str2m.find(item.first);
        if (it != str2m.end())
        {
            cross += min(it->second, item.second);
            uni += max(it->second, item.second);
        }
        else
        {
            uni += item.second;
        }
    }
    
    for (auto item : str2m)
    {
        auto it = str1m.find(item.first);
        if (it == str2m.end())
        {
            uni += item.second;
        }
    }
    
    if (str1m.empty() && str2m.empty())
    {
        answer = 65536;
    }
    else
    {
        answer = (cross * 65536) / uni;
    }
    
    
    return answer;
}