#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    vector<int> seq(26, 0);
    int idx = 1;
    for (char c : skill)
    {
        seq[c - 'A'] = idx;
        idx++;
    }
    
    for (string s : skill_trees)
    {
        int idx = 1;
        bool flag = true;
        for (char c : s)
        {
            if (seq[c - 'A'] == 0)
                continue;
            else
            {
                if (seq[c - 'A'] != idx)
                {
                    flag = false;
                    break;
                }
                
                idx++;
            }
        }
        if (flag)
            answer++;
    }
    
    return answer;
}