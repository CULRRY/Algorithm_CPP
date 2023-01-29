#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int first = 0;
    int second = 0;
    while (s != "1")
    {
        first++;
        string tmp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                tmp += s[i];
            else
                second++;
        }
    
        int sz = tmp.size();
        string result = "";
        while (sz != 0)
        {
            result = to_string(sz % 2) + result;
            sz /= 2;
        }
        s = result;
    }
    
    answer = {first, second};
    return answer;
}