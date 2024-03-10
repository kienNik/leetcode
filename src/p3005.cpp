#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int maxFrequencyElements(vector<int>& nums)
    {
        int ans = 0;

        sort(nums.begin(), nums.end());
        vector<int> fre_list;
        int fre = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] != nums[i - 1]) {
                fre_list.push_back(fre);
                fre = 1;
                continue;
            }
            ++fre;
        }
        fre_list.push_back(fre);

        sort(fre_list.begin(), fre_list.end(), greater<int>());
        int max_fre = fre_list.front();
        for (auto f : fre_list) {
            if (f == max_fre)
                ans += max_fre;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, 2, 2, 3, 1, 4};
    cout << s.maxFrequencyElements(v);
    return 0;
}