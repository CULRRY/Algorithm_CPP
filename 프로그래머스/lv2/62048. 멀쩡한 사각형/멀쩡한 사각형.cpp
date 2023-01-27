using namespace std;
using ll = long long;
ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    
    return gcd(b, a%b);
}

long long solution(int w,int h) {
    long long answer = (ll)w * (ll)h;
    ll r = gcd((ll)w, (ll)h);
    
    answer -= (ll)w + (ll)h  - gcd((ll)w, (ll)h);
    
    
    return answer;
}