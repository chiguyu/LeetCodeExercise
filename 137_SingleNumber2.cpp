#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)  {
            if(mp.find(*it) != mp.end()) {
                mp[*it] = mp[*it] + 1;
                if(mp[*it] == 3) {
                    mp.erase(*it);
                }
            } else {
                mp[*it] = 1;
            }
        }
        return mp.begin()->first;
    }
};