#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str = std::to_string(x);
        for(int i = 0; i < str.length() / 2; i++){
            if(str[i] != str[str.length() - 1 - i])
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(121);
    return 0;
}