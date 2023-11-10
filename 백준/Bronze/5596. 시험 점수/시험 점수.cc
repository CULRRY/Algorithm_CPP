#include <iostream>

using namespace std;

int main()
{
    int s = 0, t = 0;
    
    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;
        s += n;
    }
    
    for (int i = 0; i < 4; i++)
    {
        int n;
        cin >> n;
        t += n;
    }
    
    if (s >= t)
    {
        cout << s;
    }
    else
    {
        cout << t;
    }
}