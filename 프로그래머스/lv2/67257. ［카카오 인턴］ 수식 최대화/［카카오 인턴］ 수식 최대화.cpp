#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
struct Operator
{
    char oper;
    int a;
    int b;
};

ll cal(char oper, ll a, ll b)
{
    switch(oper)
    {
        case '*':
            return a * b;
        case '-':
            return a - b;
        case '+':
            return a + b;
    }
}

ll eval(vector<ll> operands, vector<Operator> operators, vector<char> order)
{
    for (int o = 0; o < 3; o++)
    {
        char now = order[o];
        for (int i = 0; i < operators.size(); i++)
        {
            auto& op = operators[i];
            if (op.oper == now)
            {
                ll tmp = cal(op.oper, operands[op.a], operands[op.b]);
                operands[op.a] = tmp;
                for (int j = i - 1; i >= 0; j++)
                {
                    if (operators[j].oper != '/')
                    {
                        operators[j].b = op.a;
                        break;
                    }
                }
                for (int j = i + 1; j < operators.size(); j++)
                {
                    if (operators[j].oper != '/')
                    {
                        operators[j].a = op.a;
                        break;
                    }
                }
                op.oper = '/';
            }
        }
    }
    
    return abs(operands[0]);
    
}



long long solution(string expression) {
    long long answer = 0;
    vector<ll> operands;
    vector<Operator> operators;
    int operandIdx = 0;
    string tmp = "";
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            tmp += expression[i];
        }
        else
        {
            operands.push_back(stoll(tmp));
            tmp = "";
            operators.push_back({expression[i], operandIdx, operandIdx+1});
            operandIdx++;
        }
    }
    operands.push_back(stoll(tmp));
    vector<char> order = {'*', '+', '-'};
    sort(order.begin(), order.end());
    
    do 
        answer = max(answer, eval(operands, operators, order));
    while(next_permutation(order.begin(), order.end()));
    
    return answer;
}