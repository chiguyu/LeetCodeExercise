#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

/*
1.将晴天的日期全部记录到 set<int> zeros中
2.无序哈希表lake_rainday记录该湖泊上一次下雨的日期
3.遇到晴天时先不决定哪个湖
4.湖泊下雨时，若此时是满的，则从lake_rainday中查询到上次下雨的日期，
  通过这个日期在晴天记录中确定抽水的日期，若可以找到就在当天抽水，若找不到则无法避免洪水返回空数组
5.处理完毕且不会发生洪水情况下，若晴天日期没有用完，则将返回数组中未处理的晴天日志置1
*/
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ret(rains.size(), -1);
        set<int> zeros;
        unordered_map<int,int> lake_rainday;

        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) {
                zeros.insert(i);
            } else {
                if (lake_rainday.find(rains[i]) == lake_rainday.end()) {
                    lake_rainday[rains[i]] = i;
                } else {
                    auto it = zeros.lower_bound(lake_rainday[rains[i]]);
                    if (it == zeros.end()) return {};
                    ret[*it] = rains[i];
                    zeros.erase(it);
                    lake_rainday[rains[i]] = i;
                }
            }
        }

        if (!zeros.empty()) {
            for (auto it = zeros.begin(); it != zeros.end(); it++) {
                ret[*it] = 1;
            }
        }

        return ret;
    }
};

int main() {
    Solution s;
    vector<int> test = {1,2,0,0,1,2};
    vector<int> res = s.avoidFlood(test);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}