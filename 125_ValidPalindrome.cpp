#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size() <= 1)
            return true;

        string test = s;
        std::transform(test.begin(), test.end(), test.begin(), ::tolower);
        int left = 0;
        int right = test.size() - 1;

        while(left < right) {
            while(left < test.size() && !isValid(test[left])) {
                left++;
            }
            while(right >= 0 && !isValid(test[right])) {
                right--;
            }

            if(left == test.size() && right == -1)
                break;
            else if(left <= right && test[left++] != test[right--])
                return false;
            else
                continue;
        }
        return true;
    }

    bool isValid(char c) {
        return isalpha(c) || isdigit(c);
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome("\"Sue,\" Tom smiles, \"Selim smote us.\"") << endl;
    return 0;
}