#include "../include/helper.hpp"

using namespace std;

class Solution
{
  public:
    int rob(vector<int>& nums, int i)
    {
        if (i < 0)
            return 0;
        return max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
    }

    int rob(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 1)
            return nums[0];
        else if (len == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[len - 1];
    }
};

int main()
{
    return 0;
}