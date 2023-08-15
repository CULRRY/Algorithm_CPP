#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long kl = k;
    long long dl = d;
    for (long long i = 0; i <= dl; i += kl)
    {
        long long b = dl*dl - i*i;
        b = sqrt(b);
        answer += b / k + 1;
    }
    
    return answer;
}