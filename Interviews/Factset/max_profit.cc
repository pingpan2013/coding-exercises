/*
 * =====================================================================================
 *
 *       Filename:  max_profit.cc
 *
 *    Description:  max profit, you can complete 2 transactions at most
 *
 *        Created:  03/09/2015 11:56:16
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1)  return 0;
        
        int n = prices.size();
        
        vector<int> profit(n, 0);
        int minBase = prices[0];
        for(int i = 1; i < n; i++){
            profit[i] = max(profit[i-1], prices[i] - minBase);
            minBase = min(minBase, prices[i]);
        }
        
        int max_profit = profit[n-1];
        
        vector<int> profit_af(n, 0);
        int maxEnd = prices[n-1];
        for(int i = n-2; i >= 0; i--){
            profit_af[i] = max(profit_af[i+1], maxEnd - prices[i]);
            maxEnd = max(maxEnd, prices[i]);
            
            // update max profit
            max_profit = max(max_profit, profit[i] + profit_af[i]);
        }
        
        return max_profit;
    }
};


