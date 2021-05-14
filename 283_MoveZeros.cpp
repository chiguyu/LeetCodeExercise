#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> index;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                index.push_back(i);
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(i < index.size()) {
                nums[i] = nums[index[i]];
            } else {
                nums[i] = 0;
            }            
        }
    }
};