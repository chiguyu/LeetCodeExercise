#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 思路：利用STL中的集合运算（交/并/差/合并）将2个入参有序数组进行合并，然后取中位数即可*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dest;
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(dest));

        int length = dest.size();
        if (length == 1) {
            return dest[0];
        } else if (length % 2) {
            return dest[length / 2];
        } else {
            return (dest[(length - 1) / 2] + dest[length / 2]) / 2.0;
        }
    }
};