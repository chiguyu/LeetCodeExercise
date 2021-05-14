#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    struct {
        bool operator()(vector<int>& a, vector<int>& b) {
            return pow(long(a[0]),2) + pow(long(a[1]),2) < pow(long(b[0]),2) + pow(long(b[1]),2);
        }
    } cmp1;

    // 排序法
    vector<vector<int>> kClosest1(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        // 自定义比较函数从小到大排序
        sort(points.begin(), points.end(), cmp1);
        for (int i = 0; i < K && i < points.size(); i++) {
            res.push_back(points[i]);
        }
        return res;
    }

    // 自定义大根堆方法，比较函数中幂次方运算存在重复运算，时间复杂度较高
    vector<vector<int>> kClosest0(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        auto cmp0 = [](vector<int> a, vector<int> b) {
            return pow(long(a[0]),2) + pow(long(a[1]),2) < pow(long(b[0]),2) + pow(long(b[1]),2);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp0)> pq(cmp0);

        for (auto &x : points) {
            if (pq.size() < K) {
                pq.push(x);
            } else if (cmp0(x, pq.top())) {
                pq.pop();
                pq.push(x);
            }
        }

        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = { {3,3},{5,-1},{-2,4}};
    vector<vector<int>> res = s.kClosest0(points, 2);
    for (auto &x : res) {
        cout << x[0] << " " << x[1] << " " << x[2] << endl;
    }

    return 0;
}