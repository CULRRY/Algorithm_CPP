#include <string>
#include <vector>

using namespace std;
using ull = unsigned long long;
constexpr ull MOD = 1'000'000'007;

int solution(int n) {
    int answer = 0;
    
    vector<ull> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] % MOD) + (dp[i - 2] % MOD);
        dp[i] %= MOD;
    }
    
    answer = dp[n];
    return answer;
}