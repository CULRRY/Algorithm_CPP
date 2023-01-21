#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct File
{
    string HEAD;
    int NUMBER;
};

File Convert(string s)
{
    File f{ "", 0};
    int idx = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] <= '9' && s[i] >= '0')
        {
            idx = i;
            break;
        }
        f.HEAD += toupper(s[i]);
    }
    string num = "";
    for (int i = idx; i < n; i++)
    {
        if (s[i] > '9' || s[i] < '0')
        {
            break;
        }
        num += s[i];
    }
    f.NUMBER = stoi(num);
    return f;
}

vector<string> solution(vector<string> files) {  
    stable_sort(files.begin(), files.end(), [](const string& s1, const string& s2)
                {
                    File f1 = Convert(s1);
                    File f2 = Convert(s2);
                    if (f1.HEAD == f2.HEAD)
                    {
                        return f1.NUMBER < f2.NUMBER;
                    }

                    return f1.HEAD < f2.HEAD;
                });
    
    return files;
}