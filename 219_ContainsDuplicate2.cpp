#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> record;
        for(int i = 0; i < nums.size(); i++) {
            if(record.find(nums[i]) != record.end()) {
                return true;
            } else {
                record.insert(nums[i]);
                if(record.size() > k) {
                    record.erase(nums[i - k]);
                }
            }
        }
        return false;
    }
};