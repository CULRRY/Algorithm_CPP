#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    std::sort(data.begin(), 
              data.end(),
              [col](const vector<int>& v1, const vector<int>& v2)
              {
                  if (v1[col-1] == v2[col-1])
                      return v1[0] > v2[0];
                  
                  return v1[col-1] < v2[col-1];
              });
    
    for (int mod = row_begin; mod <= row_end; mod++)
    {
        int sum = 0;
        for (int v : data[mod - 1])
        {
            sum += v % mod;
        }
        
        if (mod == row_begin)
        {
            answer = sum;
        }
        else
        {
            answer ^= sum;
        }
    }
        
    
    return answer;
}