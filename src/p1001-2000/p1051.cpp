#include "../include/helper.hpp"

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto expected = heights;
        sort(expected.begin(), expected.end());
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (expected[i] != heights[i]) {
                ++ans;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {3, 6, 1, 0};
    Solution s;
    return 0;
}