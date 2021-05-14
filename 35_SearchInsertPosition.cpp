#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 典型的分治思路
    int searchInsert(vector<int>& nums, int target) {
        if (nums[0] > target) {
            return 0;
        }

        // 大于最大值直接返回vector末尾
        if(nums[nums.size() - 1] < target) {
            return nums.size();
        }

        // 分治找到位置
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target ) {
                right = mid - 1;
            } else if (nums[mid] < target ) {
                left = mid + 1;
            }
        }
        
        return left;
    }
};