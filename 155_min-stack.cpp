#include <iostream>
#include <stack>
#include <set>

using namespace std;

class MinStack {
private:
    stack<int> stk;
    multiset<int> st;

public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        st.insert(val);
    }
    
    void pop() {
        if (stk.empty() || st.size() == 0) {
            return;
        }

        int stk_top = stk.top();
        st.erase(st.find(stk_top));
        stk.pop();
    }
    
    int top() {
        if (stk.empty() || st.size() == 0) {
            return -1;
        }

        return stk.top();
    }
    
    int getMin() {
        if (stk.empty() || st.size() == 0) {
            return -1;
        }

        return *(st.begin());
    }
};