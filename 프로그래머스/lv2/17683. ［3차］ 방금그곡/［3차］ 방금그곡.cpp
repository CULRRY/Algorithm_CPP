#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void Replace(string& s)
{
    string tmp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (i == s.size()-1)
        {
            tmp += s[i];
            continue;
        }
        if (s[i+1] == '#')
        {
            tmp += s[i++] + 32;
        }
        else
        {
            tmp += s[i];
        }
    }
    
    s = tmp;
}
void parse(string info, string& name, string& music, int& time)
{
    int prev = 0;
    int idx = info.find(',');
    string start = info.substr(prev, idx);

    
    prev = idx;
    idx = info.find(',', prev+1);
    string end = info.substr(prev+1, idx - prev-1);
    int starth = stoi(start.substr(0, 2));
    int startm = stoi(start.substr(3, 2));
    int endh = stoi(end.substr(0, 2));
    int endm = stoi(end.substr(3, 2));
    time = (endh - starth) * 60 + (endm - startm);
    
    prev = idx;
    idx = info.find(',', prev+1);
    name = info.substr(prev+1, idx - prev-1);
    
    music = info.substr(idx+1, info.size()-1);
    string tmp;
    Replace(music);
    
    for (int i = 0; i < time; i++)
    {
        tmp += music[i % music.size()];
        
    }
    music = tmp;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    bool flag = false;
    Replace(m);
    cout << m << endl;
    int maxtime = 0;
    for (string info : musicinfos)
    {
        string name;
        string music;
        int time;
        parse(info, name, music, time);
        int idx = music.find(m);
        cout << music << endl;
        if (music.find(m) != -1)
        {
            if (maxtime < time)
            {
                answer = name;
                maxtime = time;
            }
        }
    }
    
    if (answer == "")
        answer = "(None)";
    
    return answer;
}