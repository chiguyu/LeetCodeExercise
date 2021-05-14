#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint8_t max = log2(n);
        int res = 0;
        for(uint8_t i = 0; i <= max; i++) {
            if( n & (1 << i))
                res++;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.hammingWeight(11);
}