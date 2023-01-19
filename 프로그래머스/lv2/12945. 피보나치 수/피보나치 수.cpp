#include <string>
#include <vector>

using namespace std;
constexpr int MOD = 1234567;

int solution(int n) {
    int answer = 0;
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    answer = dp[n];
    
    return answer;
}