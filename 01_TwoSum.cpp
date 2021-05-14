#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        std::vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(map.find(complement) != map.end()) {
                res = {map[complement], i};
                break;                
            }
            map[nums[i]] = i;
        }

        return res;
    }
};

int main() {
    std::vector<int> nums = {2,7,11,5};
    int target = 9;
    Solution s;
    std::vector<int> res = s.twoSum(nums, target);
    cout << res[0] << " " << res[1];
    return 0;
}