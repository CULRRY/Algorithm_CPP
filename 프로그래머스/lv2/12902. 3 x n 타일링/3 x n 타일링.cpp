#include <string>
#include <vector>
#include <iostream>

using namespace std;
using ull = unsigned long long;
constexpr int MOD = 1'000'000'007;

int solution(int n) {
    int answer = 0;
    
    vector<ull> dp(n+1, 0);
    dp[0] = 1;
    dp[2] = 3;
    dp[4] = 11;
    
    for (int i = 6; i <= n; i += 2)
    {
        dp[i] = (dp[i-2] * 3) % MOD;
        for (int j = i - 4; j >= 0; j -= 2)
        {
            dp[i] += (2 * dp[j]) % MOD;
        }
        dp[i] %= MOD;
    }
    
    answer = dp[n];
    
    return answer;
}