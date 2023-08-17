#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    vector<int> have1(10001, 0);
    vector<int> have2(10001, 0);
    
    int h1 = 0;
    int h2 = 0;
    
    for (int i : topping)
    {
        if (have2[i]++ == 0)
            h2++;
    }

    for (int i : topping)
    {

        if (--have2[i] == 0)
            h2--;
        if (have1[i]++ == 0)
            h1++;

        if (h1 == h2)
        {
            answer++;
        }
            
    }
    
    
    
    return answer;
}