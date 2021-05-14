#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        unordered_map<int, int> mp;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)  {
            if(mp.find(*it) != mp.end()) {
                mp.erase(*it);
            } else {
                mp[*it] = 1;
            }
        }
        return mp.begin()->first;
        */
       int res = nums[0];
       for(int i = 1; i < nums.size(); i++) {
           res = res ^ nums[i];
       }
       return res;
    }
};

int main() {
    Solution s;
    vector<int> test = {4,1,2,1,2};
    cout << s.singleNumber(test) << endl;
}