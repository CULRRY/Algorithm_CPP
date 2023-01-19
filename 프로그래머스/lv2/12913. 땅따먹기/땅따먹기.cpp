#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int n = land.size();
    vector<int> window(land[0]);
    for (int i = 1; i < n; i++)
    {
        vector<int> tmp(4, 0);
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (j == k)
                    continue;
                
                tmp[j] = std::max(tmp[j], window[k]);
            }
            tmp[j] += land[i][j];
        }
        
        window = tmp;
    }
    
    answer = *max_element(window.begin(), window.end());

    return answer;
}