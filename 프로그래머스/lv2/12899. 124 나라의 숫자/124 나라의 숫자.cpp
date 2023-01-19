#include <string>
#include <vector>

using namespace std;



string solution(int n) {
    string answer = "";
    
    string table = "124";
    
    for (int i = n; i > 0;)
    {
        i--;
        answer = table[i % 3] + answer;
        i /= 3;
    }

    return answer;
}