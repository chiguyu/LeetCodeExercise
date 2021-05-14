#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 分治求解
    bool canShipWithinDays(vector<int>& weights, int D, int K) {
        int days = 1;
        int cap = K;

        for (int i = 0; i < weights.size(); i++) {
            if (K < weights[i]) {
                return false;
            }
            
            if (cap >= weights[i]) {
                cap -= weights[i];
            } else {
                days++;
                cap = K - weights[i];
            }
        }

        return days <= D;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0;
        int right = 0;
        for (auto & x : weights) {
            right += x;
        }

        while (left < right ) {
            int mid = left + (right - left) / 2;
            if (canShipWithinDays(weights, D, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};