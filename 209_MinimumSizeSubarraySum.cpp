#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int res = 0;
        int sum = 0;

        while(right < nums.size() || (sum >= s && right == nums.size())) {
            if(sum >= s) {
                res = res == 0 ? right - left : std::min(res, right - left);
                if(res == 1)
                    break;
                sum = sum - nums[left++];
            } else {
                sum = sum + nums[right++];
            }           
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> test = {2,3,1,2,4,3};
    cout << s.minSubArrayLen(7, test);
    return 0;
}