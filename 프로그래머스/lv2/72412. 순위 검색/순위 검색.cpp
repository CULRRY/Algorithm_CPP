#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#define v vector
using namespace std;

struct applicant
{
    string language;
    string position;
    string career;
    string food;
    int score;
};

int MapStr(string s)
{
    if (s == "cpp" || s == "backend" || s == "junior" || s == "chicken")
        return 0;
    if (s == "java" || s == "frontend" || s == "senior" || s == "pizza")
        return 1;
    if (s == "python")
        return 2;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    v<v<v<v<v<int>>>>> db(3, v<v<v<v<int>>>>(2, v<v<v<int>>>(2, v<v<int>>(2, v<int>()))));
    for (string i : info)
    {
        stringstream ss(i);
        applicant app;
        ss >> app.language >> app.position >> app.career >> app.food >> app.score;
        db[MapStr(app.language)][MapStr(app.position)][MapStr(app.career)][MapStr(app.food)].push_back(app.score);
    }
    
    for (string q : query)
    {
        int cnt = 0;
        applicant qry;
        stringstream ss(q);
        string trash;
        ss >> qry.language >> trash >> qry.position >> trash >> qry.career >> trash >> qry.food >> qry.score;
        vector<int> languageIdx;
        vector<int> positionIdx;
        vector<int> careerIdx;
        vector<int> foodIdx;
        if (qry.language == "-")
            languageIdx = {0, 1, 2};
        else
            languageIdx = {MapStr(qry.language)};
        
        if (qry.position == "-")
            positionIdx = {0, 1};
        else
            positionIdx = {MapStr(qry.position)};
        
        if (qry.career == "-")
            careerIdx = {0, 1};
        else
            careerIdx = {MapStr(qry.career)};
        
        if (qry.food == "-")
            foodIdx = {0, 1};
        else
            foodIdx = {MapStr(qry.food)};
        
        for (auto l : languageIdx)
            for (auto p : positionIdx)
                for (auto c : careerIdx)
                    for (auto f : foodIdx)
                    {
                        for (int s = 0; s < db[l][p][c][f].size(); s++)
                        {
                            if (db[l][p][c][f][s] >= qry.score)
                                cnt++;
                        }
                    }
        answer.push_back(cnt);
        
    }
    return answer;
}