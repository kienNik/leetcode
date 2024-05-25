#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // count number of appreances for nums' elements
        map<int, int> mp;
        for (auto i : nums) {
            ++mp[i];
        }

        vector<pair<int, int>> max_degree_list;  // list of numbers with max degree
        int degree = 0;

        for (auto i : mp) {
            if (i.second < degree) {
                continue;
            }

            if (i.second > degree) {
                degree = i.second;  
            }

            max_degree_list.push_back(i);
        }

        int result = 0;
        for (auto i : max_degree_list) {
            bool found_first = false;
            for (auto j : nums) {
                if (j == i.first) {
                    found_first = true;
                }
            }
        }

    }
};

int main()
{
    return 0;
}