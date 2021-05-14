#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0;
        int right = numbers.size() - 1;
        int sum = numbers[left] + numbers[right];
        while(left < right && sum != target ) {
            if(sum > target)
                right--;
            else
                left++;            
            sum = numbers[left] + numbers[right];
        }
        if(left < right) {
            res.push_back(left + 1);
            res.push_back(right + 1);
        }
        return res;
    }
};