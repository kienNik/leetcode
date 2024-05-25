#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int getOperationCount(vector<vector<int>>& grid, int y, int not_y)
    {
        int ans = 0;
        int box_size = grid.size();

        for (int i = 0; i < box_size; ++i) {
            for (int j = 0; j < box_size; ++j) {
                if ((i <= box_size / 2 && (i == j || i + j == box_size - 1)) ||
                    (i >= box_size / 2 && j == box_size / 2)) {
                    if (grid[i][j] != y)
                        ++ans;
                } else {
                    if (grid[i][j] != not_y)
                        ++ans;
                }
            }
        }

        return ans;
    }

    int minimumOperationsToWriteY(vector<vector<int>>& grid)
    {
        return min({getOperationCount(grid, 0, 1), getOperationCount(grid, 1, 0),
                    getOperationCount(grid, 1, 2), getOperationCount(grid, 2, 1),
                    getOperationCount(grid, 2, 0), getOperationCount(grid, 0, 2)});
    }
};

int main()
{
    vector<int> v1 = {1, 2, 2};
    vector<int> v2 = {1, 1, 0};
    vector<int> v3 = {0, 1, 0};
    vector<vector<int>> v = {v1, v2, v3};

    Solution s;
    cout << s.minimumOperationsToWriteY(v) << endl;

    return 0;
}