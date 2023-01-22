#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_set<string> hash(phone_book.begin(), phone_book.end());
    for (string& s : phone_book)
    {
        string tmp = "";
        for (char c : s)
        {
            tmp += c;
            if (tmp == s)
                continue;
            
            if (hash.find(tmp) != hash.end())
            {
                answer = false;
            }
        }
    }
    
    return answer;
}