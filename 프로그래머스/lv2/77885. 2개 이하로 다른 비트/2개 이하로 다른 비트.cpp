#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;


ll f(ll n)
{
    ll ret;
    if (n % 2 == 0)
        ret = n + 1;
    else
    {
        for (int i = 0; i <= 63; i++)
        {
            ll bit = n & (1LL << i);
            if (bit == 0)
            {
                ret = n + (1LL << (i-1));
                break;
            }
        }
    }
    
    return ret;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (ll n : numbers)
    {
        answer.push_back(f(n));
    }
    
    return answer;
}