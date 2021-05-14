#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 0)
            return 0;
        
        std::unordered_map<char, int> map;
        int left = 0;
        int right = -1;
        int ret = 1;
        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) != map.end()) {
                left = max(left, map[s[i]] + 1);
            }
            right++;

            map[s[i]] = i;
            ret = max(ret, right - left + 1);
        }
        
        return ret;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abba");
    return 0;
}