#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countInversions(const vector<int> &flatBoard)
    {
        int count = 0;
        for(int i = 0; i < flatBoard.size(); i++)
        {
            for(int j = i + 1; j < flatBoard.size(); j++)
            {
                if(flatBoard[i] != 0 && flatBoard[j] != 0 && flatBoard[i] > flatBoard[j])
                {
                    count++;
                }
            }
        }
        return count;
    }

    int slidingPuzzle(vector<vector<int>> &board)
    {
        string target = "123450";
        vector<int> flatBoard;

        for(const auto &row : board)
        {
            flatBoard.insert(flatBoard.end(), row.begin(), row.end());
        }

        if(countInversions(flatBoard) % 2 != 0)
        {
            return -1;
        }

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        string initialState = "";
        for(int num : flatBoard)
        {
            initialState += to_string(num);
        }

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({initialState, initialState.find('0')});
        visited.insert(initialState);

        int moves = 0;

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                auto [state, zeroIndex] = q.front();
                q.pop();

                if(state == target)
                {
                    return moves;
                }

                int row = zeroIndex / 3, col = zeroIndex % 3;
                for(const auto &dir : directions)
                {
                    int newRow = row + dir.first;
                    int newCol = col + dir.second;
                    if(newRow >= 0 && newRow < 2 && newCol >= 0 && newCol < 3)
                    {
                        int newZeroIndex = newRow * 3 + newCol;
                        string newState = state;
                        swap(newState[zeroIndex], newState[newZeroIndex]);

                        if(visited.find(newState) == visited.end())
                        {
                            visited.insert(newState);
                            q.push({newState, newZeroIndex});
                        }
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};