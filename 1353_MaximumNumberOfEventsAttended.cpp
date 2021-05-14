#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <functional>
#include <random>

using namespace std;

class Solution {
public:
    struct cmp {
        bool operator()(const pair<int,int>  & left, const pair<int,int>  & right) const {
            return left.second < right.second;
        }
    };
    
    int maxEvents(vector<vector<int>>& events) {
        int res = 0;

        int max_startday = events[0].front();
        int min_startday = events[0].front();
        int max_endday = events[0].back();
        int min_endday = events[0].back();
        vector<vector<int>> new_meets(max_startday + 1);  // 记录每日新增会议
        vector<vector<int>> out_of_date_meets(max_endday + 1); //记录每日过期会议
        for (int i = 0; i < events.size(); i++) {  // 遍历输入数据，初始化每日新增会议、每日过期会议
            min_startday = min(min_startday, events[i].front());
            max_startday = max(max_startday, events[i].front());
            min_endday = min(min_endday, events[i].back());
            max_endday = max(max_endday, events[i].back()); 
            if (max_startday + 1 > new_meets.size()) {
                new_meets.resize(max_startday + 1);
            }   
            if (max_endday + 1 > out_of_date_meets.size()) {
                out_of_date_meets.resize(max_endday + 1);
            }                     

            new_meets[events[i].front()].push_back(i + 1);
            out_of_date_meets[events[i].back()].push_back(i + 1);
        }

        //vector<int> attended_meets;
        multiset<pair<int,int>,cmp> available_meets;  //用已排序set记录每日可参加会议
        for (int i = min_startday; i <= max_endday; i++) {   // 按时间遍历，从可参加的会议中，选择end_day最小的会议参加
            /* 将当日新增会议添加到可参加会议列表 */
            if (i < new_meets.size()) {
                for (auto j : new_meets[i]) {
                    available_meets.insert(make_pair(j, events[j - 1].back()));
                }
            }
            
            /* 选中end_day最小的会议参加，并从可参加会议列表中移除 */
            if (!available_meets.empty()) {
                multiset<pair<int,int>,cmp>::iterator front_meet = available_meets.begin();
                //cout << "day : " << i << " attend meet_id : " << front_meet->first << endl;
                //attended_meets.push_back(front_meet->first);
                res++;
                available_meets.erase(front_meet);
            }

            /* 将当日过期会议从可参加会议列表中移除 */
            if (i >= min_endday && i < out_of_date_meets.size()) {
                for (auto k : out_of_date_meets[i]) {
                    available_meets.erase(make_pair(k, events[k - 1].back()));
                }
            }
        }

        //return attended_meets.size();
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> test = {{1,2},{2,3},{3,4}};
    cout << s.maxEvents(test) << endl;
    return 0;
}