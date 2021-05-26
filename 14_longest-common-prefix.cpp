#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;

        // 遍历得到最短字符串长度
        size_t col_max = strs[0].size();
        for (auto str : strs) {
            col_max = std::min(col_max, str.size());
        }

        // 两层循环获得最长公共前缀
        for (size_t col = 0; col < col_max; col++) {
            vector<string>::iterator it = strs.begin();
            while (it != strs.end()) {
                if (it->at(col) != strs[0][col]) {
                    break;
                }
                it++;
            }
            if (it == strs.end()) {
                prefix.push_back(strs[0][col]);
            } else {
                break;
            }
        }
        return prefix;
    }
};