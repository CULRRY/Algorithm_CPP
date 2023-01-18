#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Check(char oper, int v1, int v2, int gap)
{
    if (oper == '=')
    {
        if (abs(v1 - v2) == gap + 1)
            return true;
        return false;
    }
    else if (oper == '>')
    {
        if (abs(v1 - v2) > gap + 1)
            return true;
        return false;
    }
    else
    {
        if (abs(v1 - v2) < gap + 1)
            return true;
        return false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    string arr ="ACFJMNRT";
    
    do
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            string condition = data[i];
            int v1 = arr.find(condition[0]);
            int v2 = arr.find(condition[2]);
            char oper = condition[3];
            int gap = condition[4] - '0';
            if (!Check(oper, v1, v2, gap))
            {
                flag = false;
                continue;
            }
        }
        if (flag)
            answer++;
    }
    while (next_permutation(arr.begin(), arr.end()));
    
    return answer;
}