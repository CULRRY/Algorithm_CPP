#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i = left; i <= right; i++)
    {
        int divisor = i / n;
        int mod = i % n;
        answer.push_back(max(divisor, mod) + 1);
    }
    

    return answer;
}