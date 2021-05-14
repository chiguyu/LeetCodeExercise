#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> count;
        for (int i = 0; i < s.size(); i++) {
             count[s[i]]++;
        }

        stack<char> stk;
        unordered_map<char,bool> inStack;
        for (int i = 0; i < s.size(); i++) {
            count[s[i]]--;
            if (inStack[s[i]]) continue;
            while(!stk.empty() && stk.top() > s[i]) {
                if (count[stk.top()] == 0) break;
                inStack[stk.top()] = false;
                stk.pop();
            }
            stk.push(s[i]);
            inStack[s[i]] = true;
        }

        string result;
        while (!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    string test = "cbacdcbc";
    Solution s;
    cout << s.removeDuplicateLetters(test) << endl;
    return 0;
}