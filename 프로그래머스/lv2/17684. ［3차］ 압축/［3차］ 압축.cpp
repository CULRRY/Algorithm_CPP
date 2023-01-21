#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> dict;
    
    for (char& c : msg)
    {
        string s = "";
        s += c;
        dict[s] = c - 'A' + 1;
    }
    int c = 27;
    
    for (int i = 0; i < msg.size(); i++)
    {
        string s = "";
        
        s += msg[i];
        string prev = s;
        for (int j = i+1; j < msg.size(); j++)
        {
            prev = s;
            s += msg[j];
            
            if (dict.find(s) == dict.end())
            {
                i = j-1;

                break;
            }
            if (j == msg.size()-1)
            {
                i = j;
                prev = s;
            }
        }
        
        cout << prev << endl;
        answer.push_back(dict.find(prev)->second);
        dict[s] = c;
        c++;


    }
    
    return answer;
}