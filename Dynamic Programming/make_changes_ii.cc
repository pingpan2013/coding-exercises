/*
 * =====================================================================================
 *
 *       Filename:  make_changes_ii.cc
 *
 *    Description:  Given a list of N coins, their values (V1, V2, ... , VN), and the 
                    total sum S. Find out the total number of ways that we can make 
                    the change?
 
 *        Created:  01/14/2015 21:37:56
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution{
public:
     // Recursion
    int makeChanges_re(vector<int> coinSet, int target){
        int n = coinSet.size();

        if(target == 0)  return 1;
        if(target < 0)   return 0;
        if(n <= 0 && target > 0)    return 0;
        
        // the set without the nth coin
        vector<int> partSet(coinSet.begin(), coinSet.begin()+n-1);

        // neither include the nth coin nor doesnt include the nth coin
        return makeChanges_re(partSet, target) + makeChanges_re(coinSet, target-coinSet[n-1]);
    }
    
    // using dp
    //
    // Recursion used sub-problems many times
    // DP is actualy a bottom-up solution for Recursion
    int makeChanges_dp(vector<int> coinSet, int target){
        if(target < 0)     return 0;
        if(target == 0)     return 1;
        if(coinSet.empty()) return 0;
        
        int n = coinSet.size();
        // dp[i][j]: target is i, using coin from 1th to jth
        vector<vector<int> > dp(target+1, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            dp[0][i] = 1;

        for(int i = 1; i < target + 1;  i++)
            for(int j = 0; j < n; j++){
                int cnt = 0;

                // including s[j]
                cnt += (i >= coinSet[j]) ? dp[i-coinSet[j]][j] : 0;

                // excluding s[j]
                cnt += (j >= 1) ? dp[i][j-1] : 0;
                
                dp[i][j] = cnt;
            }
        
        return dp[target][n-1];
    }
    
    // Trivial way: DFS + BT

};


int main(){
    vector<int> coinSet;
    coinSet.push_back(1);
    coinSet.push_back(2);
    coinSet.push_back(3);

    Solution sol;
  
    // test recursion solution
    assert(sol.makeChanges_re(coinSet, 0) == 1 && "Failed in test 1");
    assert(sol.makeChanges_re(coinSet, 1) == 1 && "Failed in test 2");
    assert(sol.makeChanges_re(coinSet, 2) == 2 && "Failed in test 3");
    assert(sol.makeChanges_re(coinSet, 4) == 4 && "Failed in test 4");
    
    // test DP solution
    assert(sol.makeChanges_dp(coinSet, 0) == 1 && "Failed in test 5");
    assert(sol.makeChanges_dp(coinSet, 1) == 1 && "Failed in test 6");
    assert(sol.makeChanges_dp(coinSet, 2) == 2 && "Failed in test 7");
    assert(sol.makeChanges_dp(coinSet, 4) == 4 && "Failed in test 8");
    
    return 0;
}



