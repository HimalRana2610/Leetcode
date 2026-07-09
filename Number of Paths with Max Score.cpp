#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        int n = board.size();
        vector<int> next_score(n + 1, -1), next_ways(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> current_score(n + 1, -1), current_ways(n + 1, 0);
            for (int j = n - 1; j >= 0; --j)
            {
                if (board[i][j] == 'X')
                {
                    continue;
                }
                if (board[i][j] == 'S')
                {
                    current_score[j] = 0;
                    current_ways[j] = 1;
                    continue;
                }

                int best = max({next_score[j], current_score[j + 1], next_score[j + 1]});
                if (best == -1)
                {
                    continue;
                }

                long long ways = 0;
                if (next_score[j] == best)
                {
                    ways += next_ways[j];
                }
                if (current_score[j + 1] == best)
                {
                    ways += current_ways[j + 1];
                }
                if (next_score[j + 1] == best)
                {
                    ways += next_ways[j + 1];
                }

                int value = (board[i][j] == 'E') ? 0 : board[i][j] - '0';
                current_score[j] = best + value;
                current_ways[j] = ways % 1000000007;
            }

            next_score = move(current_score);
            next_ways = move(current_ways);
        }

        if (next_score[0] == -1)
        {
            return {0, 0};
        }

        return {next_score[0], next_ways[0]};
    }
};