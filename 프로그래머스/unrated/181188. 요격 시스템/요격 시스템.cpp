#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), [](vector<int>& v1, vector<int>& v2)
         {
             if(v1[1] == v2[1])
                 return v1[1] - v1[0] < v2[1] - v2[0];
             
             return v1[1] < v2[1];
         });
    
    int norme = -1;
    for (auto v : targets)
    {    
        if (norme <= v[0])
        {
            answer++;
            norme = v[1];
            continue;
        }   
    }
    
    return answer;
}