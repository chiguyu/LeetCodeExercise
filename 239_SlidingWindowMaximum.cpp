#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {        
        vector<int> res;       

        if(nums.size() == 0) {
            return res;
        }

        multiset<int> st;
        for(int i = 0; i < k; i++) {
            st.insert(nums[i]);
        }
        multiset<int>::reverse_iterator maxValue = st.rbegin();
        res.push_back(*maxValue);

        for(int i = k; i < nums.size(); i++) {
            st.erase(st.find(nums[i - k]));
            st.insert(nums[i]);
            multiset<int>::reverse_iterator maxValue = st.rbegin();
            res.push_back(*maxValue);
        }

        return res;
    }    
};

int main() {
    Solution s;
    vector<int> test = {-7,-8,7,5,7,1,6,0};
    vector<int> res = s.maxSlidingWindow(test, 4);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    return 0;
}