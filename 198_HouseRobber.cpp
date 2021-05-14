#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp_table(length + 2, 0);
        for (int i = length - 1; i >= 0; i--) {
            dp_table[i] = std::max(nums[i] + dp_table[i + 2], dp_table[i + 1]);
        }
        return dp_table[0];
    }
};