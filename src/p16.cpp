#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int ans = 0;
        int min_diff = INT32_MAX;
        sort(nums.begin(), nums.end());

        for (int fir = 0; fir < nums.size(); fir++) {
            int sec = fir + 1;
            int thi = nums.size() - 1;

            while (sec < thi) {
                int sum = nums[fir] + nums[sec] + nums[thi];
                int mid = sec + (thi - sec) / 2;
                sum = nums[fir] + nums[mid] + nums[thi];
                cout << nums[fir] << nums[mid] << nums[thi] << "=" << sum << endl;
                if (sum < target) {
                    sec = mid + 1;
                } else if (sum > target) {
                    thi = mid - 1;
                } else {
                    return sum;
                }
                if (abs(sum - target) < min_diff) {
                    ans = sum;
                    min_diff = abs(sum - target);
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 0, 5, -5, 3, 3, 0, -4, -5};
    cout << s.threeSumClosest(nums, -2);
    return 0;
}