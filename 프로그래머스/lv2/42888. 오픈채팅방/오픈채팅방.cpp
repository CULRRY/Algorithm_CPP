#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct Log
{
    string cmd;
    string uid;
    string name;
};

Log Parse(string log)
{
    string cmd = "", uid = "", name = "";
    int i = 0;
    for (i = 0; i < log.size(); i++)
    {
        if (log[i] == ' ')
        {
            i++;
            break;
        }
        cmd += log[i];
    }
    for (; i < log.size(); i++)
    {
        if (log[i] == ' ')
        {
            i++;
            break;
        }
        uid += log[i];
    }
    if (cmd == "Leave")
        return {cmd, uid, ""};
    
    for (int j = i; j < log.size(); j++)
    {
        name += log[j];
    }
    
    return {cmd, uid, name};
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> userInfo;
    vector<pair<int, string>> b;
    for (string l : record)
    {
        Log log = Parse(l);
        if (log.cmd == "Enter")
        {
            userInfo[log.uid] = log.name;
            b.push_back({0, log.uid});
        }
        else if (log.cmd == "Leave")
        {
            b.push_back({1, log.uid});
        }
        else
        {
            userInfo[log.uid] = log.name;
        }
    }
    
    for (auto log : b)
    {
        if (log.first == 0)
        {
            string ans = "";
            ans += userInfo[log.second];
            ans += "님이 들어왔습니다.";
            answer.push_back(ans);
        }
        else
        {
            string ans = "";
            ans += userInfo[log.second];
            ans += "님이 나갔습니다.";
            answer.push_back(ans);
        }
            
    }
    
    
    
    return answer;
}