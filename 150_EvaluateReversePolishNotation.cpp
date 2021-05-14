#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <ctype.h>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isNum(string str) {
        stringstream sin(str);
        int dec = 0;
        if(sin >> dec) 
            return true;
        else
            return false;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
            if(isNum(*it)) {
                stk.push(std::atoi((*it).c_str()));
            } else {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                if(*it == "+")
                    stk.push(num1 + num2);
                else if(*it == "-")
                    stk.push(num2 - num1);
                else if(*it == "*")
                    stk.push(num1 * num2);
                else
                    stk.push(num2 / num1);
            }
        }
        return stk.top();
    }
};