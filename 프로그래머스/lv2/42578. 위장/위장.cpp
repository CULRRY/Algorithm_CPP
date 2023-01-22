#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, unordered_set<string>> hash;
    
    for (auto& cloth : clothes)
    {
        hash[cloth[1]].insert(cloth[0]);
    }
    
    for (auto& m : hash)
    {
        answer *= m.second.size() + 1;
    }
    
    
    
    return answer-1;
}