#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            int second = i + 1;
            int third = nums.size() - 1;
            while (second < third) {
                int sum = nums[second] + nums[third] + nums[i];
                if (sum > 0) {
                    --third;
                } else if (sum < 0) {
                    ++second;
                } else {
                    vector<int> triplet = {nums[i], nums[second], nums[third]};
                    ans.push_back(triplet);

                    // remove duplicates of second number
                    while (second < third && (nums[second] == triplet[1]))
                        ++second;

                    // remove duplicates of third number
                    while (second < third && (nums[third] == triplet[2]))
                        --third;
                }
            }

            // remove duplicates of first number
            while ((i < nums.size() - 1) && (nums[i + 1] == nums[i]))
                ++i;
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    auto ans = s.threeSum(v);
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}