#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // 用于记录每个元素的频次
        // 创建自定义比较函数小根堆
        auto cmp = [](pair<int, int> left, pair<int, int> right) { return (left.second) > (right.second); };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        // 记录每个元素频次
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if(mp.find(*it) != mp.end()) {
                mp[*it]++;
            } else {
                mp[*it] = 1;
            }           
        }

        // 遍历mp，更新小根堆pq为top k数据
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            if (pq.size() < k) {
                pq.push(*it);
            } else {
                if (cmp(*it, pq.top())) {
                    pq.push(*it);
                    pq.pop();
                }
            }
        }

        // 返回值
        vector<int> res;
        while (!pq.empty()) {
            res.insert(res.begin(), pq.top().first);
            pq.pop();
        }

        return res;
    }
};