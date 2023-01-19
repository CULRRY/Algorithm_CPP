#include <string>
#include <vector>

using namespace std;
constexpr long long MOD = 1234567;

long long solution(int n) {
    long long answer = 0;
    vector<int> dp(n+1, 0);
    
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i-1] % MOD + dp[i-2] % MOD) % MOD;
    }
    
    
    return dp[n];
}