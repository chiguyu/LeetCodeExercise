#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        int left = 0;
        vector<string> res;

        if(s.size() <= 10)
            return res;
        
        for(int i = 0; i <= s.size() - WINDOW_SIZE; i++) {
            string str = s.substr(i, WINDOW_SIZE);
            if(mp.find(str) != mp.end()) {
                mp[str] = mp[str] + 1;
                if(mp[str] == 2)
                    res.push_back(str);
            } else {
                mp[str] = 1;
            }
        }

        return res;
    }
private:
    const int WINDOW_SIZE = 10;
};

int main() {
    Solution s;
    vector<string> test = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(int i = 0; i < test.size(); i++) {
        cout << test[i];
        cout << endl;
    }
    
    return 0;
}