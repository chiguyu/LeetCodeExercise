#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>mp;
        int res = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = 1;
            } else {
                mp[nums[i]]++;
                if(mp[nums[i]] > nums.size() / 2) {
                    res = nums[i];
                    break;
                }                   
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> test = {6,5,5};
    cout << s.majorityElement(test);
    return 0;
}