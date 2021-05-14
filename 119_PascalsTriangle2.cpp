#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curLine(rowIndex + 1, 1);
        for (int i = 3; i <= rowIndex + 1; i++) {
            for (int j = i - 2; j >= 1; j--) {
                if (j >= i / 2) {
                    curLine[j] = curLine[i - 2 - j] + curLine[i - j - 1];
                } else {
                    curLine[j] = curLine[i - 1 -j];
                }
            }
        }
        return curLine; 
    }
};

int main() {
    Solution s;
    vector<int> res = s.getRow(5);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}