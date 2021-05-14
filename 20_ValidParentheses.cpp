#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string left = "{[(";
        string right = "}])";
        stack<char> stk;

        for(string::iterator iterString = s.begin(); iterString != s.end(); iterString++) {
            if(left.find(*iterString) != string::npos) {
                stk.push(*iterString);
            } else {
                if(stk.empty() || stk.top() != left[right.find(*iterString)]) {
                    return false;
                } else {
                    stk.pop();
                }
            }
        }
        return stk.empty();    
    }
};

int main() {
    Solution s;
    cout << s.isValid("()[]{}");
}