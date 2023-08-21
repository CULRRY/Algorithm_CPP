#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> peach;
vector<bool> win(11, false);
int maxv = 0;

void bt(int depth, int n, vector<int>& answer)
{
    if (depth == 11)
    {

        int ls = 0;
        int ps = 0;
        int left = n;
        vector<int> lion(11, 0);
        for (int i = 0; i <= 10; i++)
        {
            if (left < 0)
            {
                return;
            }
            
            if (win[i] == true)
            {
                ls += 10 - i;
                left -= peach[i] + 1;
                lion[i] += peach[i] + 1;
            }
            else
            {
                if (peach[i] != 0)
                    ps += 10 - i;
            }
            
        }
        lion[10] += left;
        if (ls - ps > maxv)
        {
            maxv = ls - ps;
            answer = lion;

        }
        else if (ls - ps == maxv)
        {
            for (int i = 10; i >= 0; i--)
            {
                if (lion[i] > answer[i])
                {
                    answer = lion;
                    break;
                }
                else if (lion[i] < answer[i])
                {
                    break;
                }
            }
        }
        
        return;
    }
    
    bt(depth + 1, n, answer);
    
    win[depth] = true;
    bt(depth + 1, n, answer);
    win[depth] = false;

}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11, 0);
    peach = info;
    
    bt(0, n, answer);
    if (maxv == 0)
        return {-1};
    return answer;
}