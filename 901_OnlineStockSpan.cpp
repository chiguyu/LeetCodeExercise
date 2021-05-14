#include <iostream>
#include <stack>

using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> stk;
public:
    StockSpanner() {

    }
    
    int next(int price) {
        pair<int,int> current(price, 1);
        while(!stk.empty() && stk.top().first <= price) {
            current.second += stk.top().second;
            stk.pop();
        }
        stk.push(current);
        return current.second;
    }
};

int main() {
    StockSpanner test;
    cout << test.next(100) << endl;
    cout << test.next(80) << endl;
    cout << test.next(60) << endl;
    cout << test.next(70) << endl;
    cout << test.next(60) << endl;
    cout << test.next(75) << endl;
    cout << test.next(85) << endl;
    return 0;
}