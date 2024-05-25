#include "../include/helper.hpp"

class Solution
{
  public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
    {
        map<int, vector<vector<int>>> mp;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                auto distance = abs(i - rCenter) + abs(j - cCenter);
                mp[distance].push_back({i, j});
            }
        }
        vector<vector<int>> ans;
        for (auto m : mp) {
            ans.insert(ans.end(), m.second.begin(), m.second.end());
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