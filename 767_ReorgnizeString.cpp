#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        string ret = "";
        unordered_map<char,int> mp;
        for (auto c : S) {
            mp[c]++;
            if (mp[c] > (S.length() + 1) / 2)
                return ret;
        }

        auto cmp = [](const pair<char,int> & c1, const pair<char,int> & c2) {
            return c1.second < c2.second;
        };
        std::priority_queue<pair<char,int>, std::vector<pair<char,int>>, decltype(cmp)> pq(cmp);
        for (unordered_map<char,int>::iterator it = mp.begin(); it != mp.end(); it++) {
            pq.push(*it);
        }

        while (pq.size() >= 2) {
            auto root_cur = pq.top();
            ret.push_back(root_cur.first);
            root_cur.second -= 1;
            pq.pop();

            auto root_nxt = pq.top();
            ret.push_back(root_nxt.first);
            root_nxt.second -= 1;
            pq.pop();

            if (root_cur.second > 0)
                pq.push(root_cur);
            
            if (root_nxt.second > 0)
                pq.push(root_nxt);
        }

        if (!pq.empty() && pq.size() == 1) {
            ret.push_back(pq.top().first);
            pq.pop();
        }

        return ret;
    }
};

int main() {
    Solution s;
    string test = "aab";
    cout << s.reorganizeString(test) << endl;
    return 0;
}