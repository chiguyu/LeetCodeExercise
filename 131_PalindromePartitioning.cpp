#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        res.clear();
        if(s.size() == 0)
            return res;
        
        vector<string> remain;
        dfs(s, remain, 0);
        return res;
    }
    void dfs(string s, vector<string>& remain, int left) {
        if(left == s.size()) {
            res.push_back(remain);
            return;
        }

        for(int right = left; right < s.size(); right++) {
            if(isPalindrome(s, left, right)) {
                remain.push_back(s.substr(left, right - left + 1));
                dfs(s, remain, right + 1);
                remain.pop_back();   //回溯
            }
        }
    }
    bool isPalindrome(string s, int left, int right) {
        while(left < right && s[left] == s[right]) {
            left++;
            right--;
        }
        return left >= right;
    }
private:
    vector<vector<string>> res;
};