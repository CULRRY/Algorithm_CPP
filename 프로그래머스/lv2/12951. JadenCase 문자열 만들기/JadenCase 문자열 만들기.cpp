#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool mustUpper = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            mustUpper = true;
            continue;
        }
        
        if (mustUpper)
        {

            
            if (s[i] <= 'z' && s[i] >= 'a')
            {
                mustUpper = false;
                s[i] = s[i] - 32;
                continue;
            }
            
            mustUpper = false;
        }
        else
        {
            if (s[i] <= 'Z' && s[i] >= 'A')
            {
                s[i] = s[i] + 32;
                continue;
            }          
        }
        
    }
    
    return s;
}