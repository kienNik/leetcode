#include "../include/helper.hpp"

class Solution
{
  public:
    int dominantIndex(vector<int>& nums)
    {
        int max_1 = 0;
        int max_2 = 0;
        int max_idx = -1;

        for (int i = 0; i < nums.size(); ++i) {
            auto tmp = max(max_1, nums[i]);
            if (tmp > max_1) {
                max_2 = max_1;
                max_1 = tmp;
                max_idx = i;
            } else {
                max_2 = max(max_2, nums[i]);
            }
        }

        if (max_1 >= max_2 * 2) {
            return max_idx;
        }

        return -1;
    }
};

int main()
{
    vector<int> v = {3, 6, 1, 0};
    Solution s;
    cout << s.dominantIndex(v);
    return 0;
}