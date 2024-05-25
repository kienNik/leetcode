#include "../include/helper.hpp"

class Solution
{
  public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        map<int, int> arr1_freq;
        for (auto i : arr1) {
            ++arr1_freq[i];
        }

        vector<int> ans;
        for (auto i : arr2) {
            if (arr1_freq[i] > 0) {
                while (arr1_freq[i] > 0) {
                    ans.push_back(i);
                    --arr1_freq[i];
                }
            }
        }

        for (auto f : arr1_freq) {
            if (f.second == 0) {
                continue;
            }
            while (f.second > 0) {
                ans.push_back(f.first);
                --f.second;
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