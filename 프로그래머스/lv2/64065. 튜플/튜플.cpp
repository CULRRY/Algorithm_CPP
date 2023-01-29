#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<unordered_set<int>> tuples(501);
    int sz = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '{')
        {
            i++;
            string num = "";
            unordered_set<int> tmp;
            while (true)
            {
                if (s[i] == ',')
                {
                    tmp.insert(stoi(num));
                    num = "";
                    i++;
                    continue;
                }
                if (s[i] == '}')
                {
                    tmp.insert(stoi(num));
                    num = "";
                    break;
                }
                num += s[i++];
            }
            sz = max(sz, (int)tmp.size());
            tuples[tmp.size()] = tmp;
        }
    }
    
    for (int i = 1; i <= sz; i++)
    {
        for (int j : answer)
        {
            tuples[i].erase(j);
        }
        answer.push_back(*tuples[i].begin());
    }
    
    return answer;
}