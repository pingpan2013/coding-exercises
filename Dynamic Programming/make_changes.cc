/*
 * =====================================================================================
 *
 *       Filename:  make_changes.cc
 *
 *    Description:  Given a list of N coins, their values (V1, V2, ... , VN), and the 
                    total sum S. Find the minimum number of coins the sum of which is S 
                    (we can use as many coins of one type as we want), or report that 
                    it's not possible to select coins in such a way that they sum up to S. 
 *
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
    // using dp
    int makeChanges(vector<int> coinSet, int target){
        if(target <= 0) return 0;
        if(coinSet.empty()) return 0;
        
        sort(coinSet.begin(), coinSet.end());

        vector<int> dp(target + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= target; i ++){
            for(int j = 0; j < coinSet.size(); j ++){
                if(i - coinSet[j] >= 0){
                    dp[i] = min(dp[i-coinSet[j]] + 1, dp[i]);
                }    
                else 
                    continue;
            }
        }
        
        return dp[target];
    }
    
    // using dfs and backtracking
    int makeChanges_dfs(vector<int> coinSet, int target){
        if(target <= 0) return 0;
        if(coinSet.empty()) return 0;
        
        sort(coinSet.begin(), coinSet.end());
        reverse(coinSet.begin(), coinSet.end());
        
        vector<int> resSet;

        dfs(coinSet, resSet, 0, target);
        return leastCnt;
    }

private:
    int leastCnt = 0;

    void dfs(vector<int> &coinSet, vector<int> &resSet, int cnt, int target){
        if(target == 0){
            leastCnt = resSet.size(); 
            coinSet.clear();   // BT wont stop when finding the optimal solution !!! using this to stop BT
            return;            // kind of stupid
        }

        if(target < 0)  return;
        
        for(int i = cnt; i < coinSet.size(); i ++){
            resSet.push_back(coinSet[i]);
            dfs(coinSet, resSet, cnt, target - coinSet[i]);
            resSet.pop_back();
        }
    }
};


int main(){
    vector<int> coinSet({1, 3, 5});
    Solution sol;
  
    // test DP solution
    assert(sol.makeChanges(coinSet, 0) == 0 && "Failed in test 1");
    assert(sol.makeChanges(coinSet, 1) == 1 && "Failed in test 2");
    assert(sol.makeChanges(coinSet, 11) == 3 && "Failed in test 3");
    assert(sol.makeChanges(coinSet, 25) == 5 && "Failed in test 4");
  
    // test DFS solution
    // Problem: BT wont stop when finding the optimal solution
    assert(sol.makeChanges_dfs(coinSet, 0) == 0 && "Failed in test 5");
    assert(sol.makeChanges_dfs(coinSet, 1) == 1 && "Failed in test 6");
    assert(sol.makeChanges_dfs(coinSet, 11) == 3 && "Failed in test 7");
    assert(sol.makeChanges_dfs(coinSet, 25) == 5 && "Failed in test 8");
    
    return 0;
}



