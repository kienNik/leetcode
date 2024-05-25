#include "../include/helper.hpp"

class Solution
{
  public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int n = matrix.size();
        int m = matrix.front().size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int max_size = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i + 1][j + 1] = min({dp[i][j], dp[i][j + 1], dp[j][i + 1]}) + 1;
                    max_size = max(max_size, dp[i + 1][j + 1]);
                }
            }
        }

        return max_size * max_size;
    }
};

int main()
{
    Solution s;
    vector<char> v1 = {'0'};
    vector<char> v2 = {'1'};
    vector<vector<char>> v3 = {v1, v2};
    cout << s.maximalSquare(v3);
    return 0;
}