#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<int> table(24 * 60, 0);
    
    for (vector<string>& v : book_time)
    {
        int startTime = stoi(v[0].substr(0, 2)) * 60 + stoi(v[0].substr(3, 2));
        int lastTime = std::min(stoi(v[1].substr(0, 2)) * 60 + stoi(v[1].substr(3, 2)) + 9, 23*60 + 59);
        
        //cout << startTime << " " << lastTime << endl;
        
        for (int i = startTime; i <= lastTime; i++)
        {
            table[i]++;
        }
    }
    
    answer = *max_element(table.begin(), table.end());
    return answer;
}