#include<bits/stdc++.h>
using namespace std;

class Spreadsheet
{
    vector<vector<int>> sheet;
    int r, c = 26;

    public:
    Spreadsheet(int rows)
    {
        r = rows;
        sheet.assign(r, vector<int>(c, 0));
    }

    void setCell(string cell, int value)
    {
        int col = cell[0] - 'A', row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = value;
    }

    void resetCell(string cell)
    {
        int col = cell[0] - 'A', row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = 0;
    }

    int evaluate(string str)
    {
        if(isdigit(str[0]))
        {
            return stoi(str);
        }

        int col = str[0] - 'A', row = stoi(str.substr(1)) - 1;
        return sheet[row][col];
    }

    int getValue(string formula)
    {
        string expression = formula.substr(1);
        int pos = expression.find('+');
        string p1 = expression.substr(0, pos), p2 = expression.substr(pos + 1);

        return evaluate(p1) + evaluate(p2);
    }
};