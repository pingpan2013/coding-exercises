/*
 * =====================================================================================
 *
 *       Filename:  maxProfit.cc
 *
 *    Description:  Best time to sell and buy stock, version 2
 *                  You could complete as many transactions as 
 *                  you like
 *
 *        Created:  10/19/2014 04:12:53 PM
 *       Compiler:  g++ 4.7.0
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
        
        int curMaxIncrement = 0;
        for(vector<int>::size_type i = 1; i < prices.size(); i ++){
            if(prices[i] - prices[i-1] > 0)
                curMaxIncrement += prices[i] - prices[i-1];
        }

        return curMaxIncrement;
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
    vec.push_back(2);
    vec.push_back(3);
    assert(sol.maxProfit(vec) == 8 && "failed in null input test!");

    cout << "Passed all the tests!" << endl;

    return 0;
}



