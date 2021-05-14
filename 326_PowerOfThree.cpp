#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 3) {
            if(n == 1) {
                return true;
            } else {
                return false;
            }
        } else {
            if(n % 3 != 0){
                return false;
            } else {
                return isPowerOfThree(n / 3);
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.isPowerOfThree(60);
    return 0;
}