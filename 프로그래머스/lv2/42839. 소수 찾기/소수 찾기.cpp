#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;
unordered_set<int> memo;
vector<bool> isUsed;
int answer = 0;
void bt (int depth, string nums, string tmp)
{
    if (depth == nums.size())
        return;
    string t = tmp;
    sort(t.begin(), t.end());
    do
    {
        int n = stoi(t);
        if (memo.find(n) != memo.end())
        {
            continue;
        }
        else
        {
            memo.insert(n);
        }
                
        bool flag = true;
        if (n == 1 || n == 0)
            flag = false;
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {   
            answer++;
        }
                    
    }
    while (next_permutation(t.begin(), t.end()));
    
    for (int i = 0; i < nums.size(); i++)
    {
        if (isUsed[i] == false)
        {
            isUsed[i] = true;
            bt(depth, nums, tmp + nums[i]);
            isUsed[i] = false;
        }
    }
}
int solution(string numbers) {
    
    isUsed.assign(numbers.size(), false);
    sort(numbers.begin(), numbers.end());
    
    for (int i = 0; i < numbers.size(); i++)
    {
        isUsed[i] = true;
        string tmp = "";
        tmp += numbers[i];
        bt(1, numbers, tmp);
        isUsed[i] = false;
    }
    
    return answer;
}