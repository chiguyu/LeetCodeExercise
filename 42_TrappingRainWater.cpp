#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int length = height.size();
        if (length <= 2) return 0;
        vector<int> l_max(length);
        vector<int> r_max(length);

        l_max[0] = height[0];
        for (int i = 1; i < length; i++) {
            l_max[i] = max(height[i], l_max[i - 1]);

        }

        r_max[length - 1] = height[length - 1];
        for (int i = length - 2; i >= 0; i--) {
            r_max[i] = max(height[i], r_max[i + 1]);
        }

        for (int i = 0; i < length; i++) {
            res += max(min(l_max[i], r_max[i]) - height[i] , 0);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> test = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(test) << endl;
    return 0;
}