#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    
    while (true)
    {
        bool flag = true;
        for (int& i : arr)
        {
            if (answer % i != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            break;
        answer++;
            
        
    }
    
    return answer;
}