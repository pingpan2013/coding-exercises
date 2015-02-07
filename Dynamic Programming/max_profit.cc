/*
 * =====================================================================================
 *
 *       Filename:  maxProfit.cc
 *
 *    Description:  Best time to sell and buy stock
 *
 *        Created:  10/19/2014 04:12:53 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <climits>
#include <cmath>
#include <cassert>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int> prices){
        if(prices.empty())  return 0;

        int curBase = prices[0];
        int maxProf = INT_MIN;
    
        for(vector<int>::size_type i = 0; i < prices.size(); i ++){
            maxProf = max(maxProf, prices[i]-curBase);
            curBase = min(curBase, prices[i]);
        }

        return maxProf;
    }
};

int main(){
    Solution sol;
    
    vector<int> vec;
    assert(sol.maxProfit(vec) == 0 && "failed in null input test!");
    
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(3);
    vec.push_back(8);
    assert(sol.maxProfit(vec) == 5 && "failed in null input test!");
   
    return 0;
}



