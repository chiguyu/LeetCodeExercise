#include <vector>

using namespace std;

/* 思路：左右指针，每次循环进入时刷新找到的最大面积，并移动短板 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        while (left < right) {
            int area = std::min(height[left], height[right]) * (right - left);
            res = std::max(res, area);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};