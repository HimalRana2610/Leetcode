#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<int> arr(n * n + 1, -1);
        arr[1] = 0;

        queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int i = current + 1; i <= min(current + 6, n * n); i++)
            {
                int row = (i - 1) / n, col = (i - 1) % n;
                int next = i;

                if (board[n - 1 - row][(row % 2) ? n - 1 - col : col] != -1)
                {
                    next = board[n - 1 - row][(row % 2) ? n - 1 - col : col];
                }

                if (next == n * n)
                {
                    return arr[current] + 1;
                }
                if (arr[next] == -1)
                {
                    arr[next] = arr[current] + 1;
                    q.push(next);
                }
            }
        }

        return -1;
    }
};