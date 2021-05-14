#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int target = 0 - nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                if(nums[j] + nums[k] == target){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    res.push_back(temp);
                    while(j < k && nums[j] == nums[++j]);
                    while(j < k && nums[k] == nums[--k]);
                } else if (nums[j] + nums[k] > target){
                    while(j < k && nums[k] == nums[--k]);
                } else {
                    while(j < k && nums[j] == nums[++j]);
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 1, 2, -1, -1, -4};
    Solution s;
    vector<vector<int>> res = s.threeSum(nums);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}