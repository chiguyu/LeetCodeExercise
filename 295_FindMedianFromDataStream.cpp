#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
public: 
    void addNum(int num) {
        maxPq.push(num);
        minPq.push(maxPq.top());
        maxPq.pop();
        if(maxPq.size() < minPq.size()) {
            maxPq.push(minPq.top());
            minPq.pop();
        }

    }
    
    double findMedian() {
        double res = 0.0;
        if(maxPq.size() == minPq.size()) {
            res = (maxPq.top() + minPq.top()) / 2.0;
        } else {
            res = maxPq.top();
        }
        return res;
    }

private:
    priority_queue<int> maxPq;
    priority_queue<int, vector<int>, greater<int>> minPq;
};