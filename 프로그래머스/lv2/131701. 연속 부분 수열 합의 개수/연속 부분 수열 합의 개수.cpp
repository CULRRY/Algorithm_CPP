#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int n = elements.size();
    unordered_set<int> nums;
    vector<int> pre;
    pre.push_back(0);
    int sum = 0;
    for (int i : elements)
    {
        sum += i;
        pre.push_back(sum);
    }
    
    for (int d = 0; d < n; d++)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i + d + 1;
            int mod = -1;
            int out = 0;
            if (j > n)
            {
                mod = (i + d) % n;
                out = pre[n] - pre[i];
            }
            else
                out = pre[j] - pre[i];
            if (mod != -1)
            {
                out += pre[mod + 1];
            }
            if (nums.find(out) == nums.end())
            {
                answer++;
                nums.insert(out);
            }
        }
    }
    
    return answer;
}