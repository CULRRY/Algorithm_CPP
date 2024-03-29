#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<bool> isUsed;


int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    
    for (int i = 0; i < B.size(); i++)
    {
        answer += A[i] * B[i];
    }

    return answer;
}