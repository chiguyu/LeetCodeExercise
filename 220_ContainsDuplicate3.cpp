#include <iostream>
#include <vector>
#include <set>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> record;
        for(int i = 0; i < nums.size(); i++) {
            if(!record.empty()) {
                multiset<int>::iterator itHead = record.begin();
                multiset<int>::reverse_iterator itEnd = record.rbegin();
                if(abs(*itHead - nums[i]) <= t || abs(*itEnd - nums[i]) <= t) {
                    return true;
                } 
            }
            
            record.insert(nums[i]);
            if(record.size() > k) {
                record.erase(record.find(nums[i - k]));
            }           
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> test = {1,5,9,1,5,9};
    cout << s.containsNearbyAlmostDuplicate(test, 2, 3);
    return 0;
}