#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        
        const int FIRST_BOUGHT = 0; //首次买入状态
        const int FIRST_SOLD = 1; //首次卖出状态
        const int SEC_BOUGHT = 2;  //第二次买入状态
        const int SEC_SOLD = 3;  //第二次卖出状态
        /*
        * profit[FIRST_BOUGHT]:当天若是首次买入状态时的最大收益
        * profit[FIRST_SOLD]:当天若是首次卖出状态时的最大收益 
        * profit[SEC_BOUGHT]:当天若是二次买入状态时的最大收益
        * profit[SEC_SOLD]:当天若是首次卖出状态时的最大收益 
        */
        int profit[4] = {0}; 

        profit[FIRST_BOUGHT] = 0 - prices[0];
        if(prices.size() >= 3)
            profit[SEC_BOUGHT] = prices[1] - prices[0] - prices[2];
        
        for(int i = 1; i < prices.size(); i++) {
            if(profit[FIRST_BOUGHT] + prices[i] > profit[FIRST_SOLD]) //若第i天是首次卖出状态(前一天一定是首次买入状态)，若当天操作卖出比当天不进行交易收益高
                profit[FIRST_SOLD] = profit[FIRST_BOUGHT] + prices[i];
            if(0 - prices[i] > profit[FIRST_BOUGHT])  //若第i天是首次买入状态，若当天操作买入比当天不进行交易收益高
                profit[FIRST_BOUGHT] = 0 - prices[i];
            
            if(i >= 3 && profit[SEC_BOUGHT] + prices[i] > profit[SEC_SOLD])  //若第i天是二次卖出状态，若当天操作卖出(前一天一定是二次买入状态)比当天不进行交易收益高
                profit[SEC_SOLD] = profit[SEC_BOUGHT] + prices[i];
            if(i >= 2 && profit[FIRST_SOLD] - prices[i] > profit[SEC_BOUGHT])  //若第i天是二次买入状态，若当天操作买入(前一天一定是首次卖出状态)比当天不进行交易收益高
                profit[SEC_BOUGHT] = profit[FIRST_SOLD] - prices[i];
        }

        return max(profit[FIRST_SOLD], profit[SEC_SOLD]);
    }
};

int main() {
    Solution s;
    vector<int> test = {73,3,5,0,0,3,1,4};
    cout << s.maxProfit(test) << endl;
}