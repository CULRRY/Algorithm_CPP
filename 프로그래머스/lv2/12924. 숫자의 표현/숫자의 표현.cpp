#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> v;
    int sum = 0;
    v.push_back(sum);
    for (int i = 1; i <= n; i++)
    {
        sum += i;
        v.push_back(sum);
    }
    
    int left = 0;
    int right = 1;
    int cnt = 0;
    while (left < n)
    {
        int val = v[right] - v[left];
        
        if (val == n)
        {
            left++;
            right++;
            cnt++;
        }
        else if (val > n)
        {
            left++;
        }
        else
        {
            right++;
        }
        
    }
    
    answer = cnt;
    
    return answer;
}