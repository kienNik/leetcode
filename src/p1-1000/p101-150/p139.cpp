#include "../include/helper.hpp"

class Solution
{
  public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        set<string> dict;
        for (auto const& word : wordDict) {
            dict.insert(word);
        }

        int len = s.size();
        vector<bool> dp(len, false);  // dp[i] is whether substr from begin to index i can be
                                      // divided into words

        // check if substr from begin to index i can be divided
        for (int i = 0; i < len; ++i) {
            // if substr in dict then dp[i] = true
            if (dict.find(s.substr(0, i + 1)) != dict.end()) {
                dp[i] = true;
                continue;
            }
            // break substr into 2 parts: [0,j] and [j+1,i]
            // substr can be divided if [0,j] can be divided and [j+1,i] is in dict
            // which is dp[j]=true and [j+1,i] is in dict
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j + 1, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp.back();
    }
};

int main()
{
    Solution s;
    return 0;
}