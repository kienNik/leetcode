#include "../include/helper.hpp"

class Solution
{
  public:
    string longestPalindrome(string s)
    {
        string ans{s.front()};
        for (int i = 0; i < s.size() - 1; ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                int len = j - i + 1;
                bool is_palin = false;
                for (int k = 0; k < len / 2; ++k) {
                    if (s[i + k] != s[j - k]) {
                        is_palin = false;
                        break;
                    }
                    is_palin = true;
                }
                if (!is_palin) {
                    continue;
                }
                auto sub_str = s.substr(i, len);
                if (sub_str.size() > ans.size()) {
                    ans = sub_str;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("babad");
    return 0;
}