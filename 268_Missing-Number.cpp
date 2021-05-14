#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            sum -= *it;
        }
        return sum;
    }
};