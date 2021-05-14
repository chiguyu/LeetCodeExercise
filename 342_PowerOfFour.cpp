#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 4) {
            if(num == 1) {
                return true;
            } else {
                return false;
            }
        } else {
            if(num % 4 != 0){
                return false;
            } else {
                return isPowerOfFour(num / 4);
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.isPowerOfFour(16);
    return 0;
}