#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    int n;
    while (cin >> n)
    {
        long long rule = 1;
        int count = 1;
        
        while (true)
        {

            if (rule % n == 0)
                break;

            rule = (rule * 10)%n + 1;
            count++;

        }
        std::cout << count << "\n";
    }
    return 0;
}