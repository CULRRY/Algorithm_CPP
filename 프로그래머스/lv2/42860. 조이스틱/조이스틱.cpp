#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int answer = 98765442;
vector<bool> memo;
void bt(int sum, string s, int idx, string name, int moveCnt)
{
    if (name[idx] > s[idx])
    {
        sum += min(name[idx] - s[idx], s[idx] - 'A' + 'Z' - name[idx] + 1);
    }
    else if (name[idx] == s[idx])
    {
        
    }
    else
    {
        sum += min(s[idx] - name[idx], 'Z' - s[idx] + name[idx] - 'A' + 1);
    }
    s[idx] = name[idx];
    if (s == name)
    {
        
        answer = std::min(answer, sum + moveCnt);
        return;
    }
    
    if (moveCnt >= s.size())
        return;
    
    int nidx = idx - 1;
    if (nidx < 0)
        nidx = name.size() - 1;
    
    bt(sum, s, nidx, name, moveCnt + 1);
    
    nidx = idx + 1;
    if (nidx >= name.size())
        nidx = 0;
    
    bt(sum, s, nidx, name, moveCnt + 1);
}
int solution(string name) {
    string basic(name.size(), 'A');
    memo.assign(name.size(), false);
    bt(0, basic, 0, name, 0);
    return answer;
}