#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    
    unordered_set<string> s;
    
    int turn = 0;
    int idx = 0;
    string prev = "";
    for (string& word : words)
    {
        if (turn == 0)
        {
            idx++;
        }
        if (s.find(word) != s.end())
        {
            answer = {turn + 1, idx};
            break;
        }
        
        if (prev != "")
        {
            if (prev.back() != word[0])
            {
                answer = {turn + 1, idx};
                break;
            }
        }
        
        s.insert(word);
        turn = (turn + 1) % n;
        prev = word;
    }

    return answer;
}