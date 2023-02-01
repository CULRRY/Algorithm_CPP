#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string alphabet = "AEIOU";
vector<string> words;
vector<bool> isUsed(5);

void bt(int depth, string s)
{
    if (depth == 6)
    {
        return;
    }
    words.push_back(s);
    
    for (int i = 0; i < 5; i++)
    {
            bt(depth + 1, s + alphabet[i]);
    }
}

int solution(string word) {
    int answer = 0;
    
    bt(0, "");
    
    sort(words.begin(), words.end());
    answer = find(words.begin(), words.end(), word) - words.begin();
    return answer;
}