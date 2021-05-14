#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        vector<int>::iterator it1 = nums.begin();
        vector<int>::iterator it2 = it1 + 1;
        while(it2 != nums.end()) {
            if(*it1 != *it2) {
                *(++it1) = *(it2++);
            } else {
                it2++;
            }
        }
        nums.erase(++it1, nums.end());
        return nums.size();
    }
};

int main() {
    vector<int> test = {0,0,1,1,1,2,2,3,3,4};
    Solution s;
    cout << s.removeDuplicates(test) << endl;
    for(int i = 0; i < test.size(); i++)
        cout << test[i];
    cout << endl;
    return 0;
}