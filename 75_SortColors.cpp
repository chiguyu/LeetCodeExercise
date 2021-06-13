#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

/*
使用桶排序思路解决
1.创建red/white/blue 3种空桶
2.遍历输入数组，依次将数据放入合适的桶中
3.合并3个桶的数据，并写入nums
*/
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
        
        nums.clear();
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