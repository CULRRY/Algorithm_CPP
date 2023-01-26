#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    
    for (int r = 3; r <= 3000; r++)
    {
        for (int c = r; r * c <= brown + yellow; c++)
        {
            if (2*(r+c) - 4 == brown)
            {
                if ((r-2) * (c-2) == yellow)
                {
                    answer[0] = c;
                    answer[1] = r;
                    return answer;
                }
            }
        }
    }
    
    return answer;
}