#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        if(numRows <= 0)
            goto EXIT; 

        res.push_back(vector<int>{1});
        if(numRows == 1)
            goto EXIT; 

        res.push_back(vector<int>{1, 1});
        if(numRows == 2)
            goto EXIT; 

        for (int i = 3; i <= numRows; i++) {
            vector<int> curLine(i, 1);
            for (int j = 1; j < i - 1; j++){
                curLine[j] = res[i - 2][j - 1] + res[i - 2][j];
            }
            res.push_back(curLine);
        }
EXIT:
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> res = s.generate(5);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}