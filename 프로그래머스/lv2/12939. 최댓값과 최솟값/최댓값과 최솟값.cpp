#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    string num;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            v.push_back(stoi(num));
            num = "";
            continue;
        }
        
        num += s[i];
    }
    v.push_back(stoi(num));
    
    sort(v.begin(), v.end());
    
    int min = v[0];
    int max = v.back();
    string mins;
    string maxs;
    
    mins = to_string(min);
    maxs = to_string(max);
    
    answer = mins + " " + maxs;
    return answer;
}