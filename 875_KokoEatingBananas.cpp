#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canEatWithinHours(vector<int>& piles, int H, int speed) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] % speed == 0) {
                hours += piles[i] / speed;
            } else {
                hours += piles[i] / speed + 1;
            }
        }
        return hours <= H;
    }

    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 0;
        int right = 0;
        for (auto & x : piles) {
            right = max(right, x);
        }

        // 二分查找 —— 分而治之 
        while (left < right ) {
            int mid = left + (right - left) / 2;
            if (mid > 0 && canEatWithinHours(piles, H, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};