#include<iostream>

using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < 5; i++)
    {
        int a;
        cin >> a;
        if (a == n)
            cnt++;
    }
    
    cout << cnt;
        
}