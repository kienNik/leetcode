#include "../include/helper.hpp"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int ans = 0;
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

        for (int i = 0; i <= len1; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= len2; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    auto use_convert = dp[i - 1][j - 1] + 1;
                    auto use_delete = dp[i - 1][j] + 1;
                    auto use_insert = dp[i][j - 1] + 1;
                    dp[i][j] = min({use_convert, use_delete, use_insert});
                }
            }
        }
        return dp[len1][len2];
    }
};

int main()
{
    Solution s;
    return 0;
}