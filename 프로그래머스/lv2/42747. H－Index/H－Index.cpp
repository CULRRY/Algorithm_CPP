#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    sort(citations.begin(), citations.end());
    
    for (int h = 0; h <= 10000; h++)
    {
        auto lw = lower_bound(citations.begin(), citations.end(), h);
        if (lw == citations.end())
        {
            continue;
        }
        
        int idx = lw - citations.begin();
        if (idx > h)
        {
            continue;
        }
        
        if (citations.size() - idx < h)
            continue;
        
        answer = h;
    }
    
    return answer;
}