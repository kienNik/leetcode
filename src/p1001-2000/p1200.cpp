#include "../../include/helper.hpp"

class Solution
{
  public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        sort(arr.begin(), arr.end());
        int arr_len = arr.size();
        int min_diff = INT8_MAX;

        vector<vector<int>> ans;
        for (int i = 1; i < arr_len; ++i) {
            int diff = abs(arr[i] - arr[i - 1]);
            if (diff > min_diff) {
                continue;
            }

            if (diff < min_diff) {
                min_diff = diff;
                ans.clear();
            }

            ans.push_back({arr[i - 1], arr[i]});
        }

        return ans;
    }
};

int main()
{
    vector<int> v = {4, 2, 1, 3};
    Solution s;
    s.minimumAbsDifference(v);
    return 0;
}