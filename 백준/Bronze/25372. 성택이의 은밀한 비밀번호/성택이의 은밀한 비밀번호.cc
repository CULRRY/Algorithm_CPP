#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    while(n--)
    {
        string s;
        cin >> s;
        
        if (s.size() < 6 || s.size() > 9)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
}