#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> res;

        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)  {
            if(mp.find(*it) != mp.end()) {
                mp.erase(*it);
            } else {
                mp[*it] = 1;
            }
        }

        for(unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            res.push_back(it->first);
        }
        return res;
    }
};