#include "../include/helper.hpp"

class Solution {
public:
    int minDistance(string word1, string word2) {
        int ans = 0;
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));

        for (int i = 0; i <= len1; ++i) {
            dp[i][len2] = len1 - i;
        }
        for (int j = 0; j <= len2; ++j) {
            dp[len1][j] = len2 - j;
        }

        for (int i = len1 - 1; i >= 0; --i) {
            for (int j = len2 - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    int insert = dp[i][j+1] + 1;
                    int erase = dp[i+1][j] + 1;
                    int replace = dp[i+1][j+1] + 1;
                    dp[i][j] = min({insert, erase, replace});
                }
            }
        }
        
        return dp[0][0];
    }
};

int main()
{
    Solution s;
    return 0;
}