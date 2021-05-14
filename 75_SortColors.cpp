#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0)
            return;

        vector<int> red;
        vector<int> white;
        vector<int> blue;

        for(std::vector<int>::iterator it = nums.begin() ; it != nums.end(); ++it){
            if( *it == 0) {
                red.push_back(*it);
            } else if (*it == 1) {
                white.push_back(*it);
            } else {
                blue.push_back(*it);
            }
        }
        
        nums.erase(nums.begin(), nums.end());
        nums.insert(nums.end(), red.begin(), red.end());
        nums.insert(nums.end(), white.begin(), white.end());
        nums.insert(nums.end(), blue.begin(), blue.end());
    }
};

int main() {
    vector<int> test = {2,0,2,1,1,0};
    Solution s;
    s.sortColors(test);
    for(int i = 0; i < test.size(); i++)
        cout << test[i];
    cout << endl;
    return 0;
}