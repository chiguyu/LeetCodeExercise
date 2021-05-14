#include <iostream>
#include <math.h>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned int d = INT_MAX;
        while((m & d) != (n & d)) {
            d = d << 1;
        }
        return m & d;
    }
};