#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        /*
        priority_queue<int> profits;
        int buy = prices[0];       
        for(int i = 0; i < prices.size() - 1; i++) {           
            if(i > 0 && prices[i] >= buy)
                continue;           
            buy = prices[i];
            int sell = prices[i + 1];
            for(int j = i + 1; j < prices.size(); j++) {
                if(j > i + 1 && prices[j] <= sell)
                    continue;
                sell = prices[j];
                profits.push(sell - buy);
            }
        }

        if(profits.empty() || profits.top() < 0)
            return 0;
        else 
            return profits.top();
        */

        /*
        int debt = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            profit = max(profit, prices[i] - debt);
            debt = min(debt, prices[i]);
        }
        return profit;
        */

       /*
        int debt = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] - debt > profit)
                profit = prices[i] - debt;
            if(prices[i] < debt )
                debt = prices[i];
        }
        return profit;
        */

        const int BOUGHT = 0;  //买入状态
        const int SOLD = 1;  //卖出状态
        /*
        * profit[BOUGHT]:当天若是买入状态时的最大收益
        * rofit[SOLD]:当天若是卖出状态时的最大收益 
        */
        int profit[2] = {0};

        profit[BOUGHT] = 0 - prices[0];
        for(int i = 1; i < prices.size(); i++) {
            if(profit[BOUGHT] + prices[i] > profit[SOLD]) //若第i天是卖出状态，若当天操作卖出(前一天一定是买入状态)比当天不进行交易收益高
                profit[SOLD] = profit[BOUGHT] + prices[i];
            if(0 - prices[i] > profit[BOUGHT])  //若第i天是买入状态，若当天操作买入比当天不进行交易收益高
                profit[BOUGHT] = 0 - prices[i];
        }
        return profit[SOLD];
    }
};

int main() {
    Solution s;
    vector<int> test = {7,1,5,3,6,4};
    cout << s.maxProfit(test) << endl;
}