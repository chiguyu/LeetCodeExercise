#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n < 1 ? false : !(n & (n - 1));
    }
};