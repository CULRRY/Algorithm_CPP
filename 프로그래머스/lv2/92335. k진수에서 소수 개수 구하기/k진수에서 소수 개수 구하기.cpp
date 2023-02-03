#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;
bool isPrime(ll n)
{
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    
    for (ll i = 2; i <= sqrt((double)n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

string baseConversion(int n, int k)
{
    static string numbers = "0123456789";
    string ret = "";
    while (n > 0)
    {
        ret = numbers[n % k] + ret;
        n /= k;
    }
    
    return ret;
}

int solution(int n, int k) {
    int answer = 0;
    vector<ll> nums;
    string base = baseConversion(n, k);
    string tmp = "";
    for (int i = 0; i < base.size(); i++)
    {
        if (base[i] == '0')
        {
            if (tmp != "")
                nums.push_back(stoll(tmp));
            tmp = "";
        }
        else
        {
            tmp += base[i];
        }
    }
    if (tmp != "")
        nums.push_back(stoll(tmp));
    
    for (ll i : nums)
    {
        if (isPrime(i))
            answer++;
    }
    
    return answer;
}