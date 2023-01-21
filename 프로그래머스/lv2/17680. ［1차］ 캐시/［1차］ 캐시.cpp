#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    list<string> cache(cacheSize);
    int front = 0;
    int back = 0;
    
    for (string& s : cities)
    {
        for (char& c : s)
        {
            c = tolower(c);
        }
        int time = 5;
        string hit = "";
        for (auto it = cache.begin(); it != cache.end(); ++it)
        {
            if (*it == s)
            {
                time = 1;
                hit = s;
                cache.erase(it);
                break;
            }
        }
        
        if (hit != "")
        {
            cache.push_front(s);
        }
        else
        {
            cache.push_front(s);
            if (cache.size() > cacheSize)
                cache.pop_back();
        }
        answer += time;
    
    }
    
    
    return answer;
}