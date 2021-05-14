#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carrier = 1;

        for(int i = digits.size() - 1; i >= 0 && carrier > 0; i--) {
            int sum = digits[i] + carrier;
            /*
            digits[i] = sum % 10;
            carrier = sum / 10;
            */
           digits[i] = sum >= 10 ? sum - 10 : sum;
           carrier = sum >= 10 ? 1 : 0;
        }

        if(carrier == 1)
            digits.insert(digits.begin(), carrier);

        return digits;
    }
};

int main() {
    vector<int> test = {4,3,2,1};
    Solution s;
    vector<int> res = s.plusOne(test);
    for(int i = 0; i < res.size(); i++)
        cout << res[i];
    cout << endl;
    return 0;
}