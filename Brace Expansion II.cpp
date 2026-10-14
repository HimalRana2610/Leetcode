#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void ope(vector<set<string>> &stk, vector<char> &op)
    {
        int l = stk.size() - 2, r = stk.size() - 1;
        if (op.back() == '+')
        {
            stk[l].merge(stk[r]);
        }
        else
        {
            set<string> tmp;
            for (auto &left : stk[l])
            {
                for (auto &right : stk[r])
                {
                    tmp.insert(left + right);
                }
            }
            stk[l] = move(tmp);
        }
        op.pop_back();
        stk.pop_back();
    }

    vector<string> braceExpansionII(string expression)
    {
        vector<char> op;
        vector<set<string>> stk;

        for (int i = 0; i < expression.size(); i++)
        {
            if (expression[i] == ',')
            {
                while (op.size() && op.back() == '*')
                {
                    ope(stk, op);
                }
                op.push_back('+');
            }
            else if (expression[i] == '{')
            {
                if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1])))
                {
                    op.push_back('*');
                }
                op.push_back('{');
            }
            else if (expression[i] == '}')
            {
                while (op.size() && op.back() != '{')
                {
                    ope(stk, op);
                }
                op.pop_back();
            }
            else
            {
                if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1])))
                {
                    op.push_back('*');
                }
                stk.push_back({string(1, expression[i])});
            }
        }

        while (op.size())
        {
            ope(stk, op);
        }

        return {stk.back().begin(), stk.back().end()};
    }
};