#include "../include/helper.hpp"

class Solution
{
  public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes)
    {
        set<int> bob;
        int alice_sum = 0;
        int bob_sum = 0;

        for (auto i : aliceSizes) {
            alice_sum += i;
        }

        for (auto j : bobSizes) {
            bob_sum += j;
            bob.insert(j);
        }

        // suma: alice_sum, sumb: bob_sum
        // suma - a[i] + b[j] = sumb + a[i] - b[j]
        // b[j] = (sumb - suma)/2 + a[i]
        vector<int> ans;
        int foo = (bob_sum - alice_sum) / 2;
        for (auto i : aliceSizes) {
            if (bob.count(foo + i)) {
                ans.push_back(i);
                ans.push_back(foo + i);
                break;
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