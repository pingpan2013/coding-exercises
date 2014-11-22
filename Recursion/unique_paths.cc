/*
 * =====================================================================================
 *
 *       Filename:  unique_paths.cc
 *
 *    Description:  A robot is located at the top-left corner of a m x n grid (marked 
 *    'Start' in the diagram below).
 *    The robot can only move either down or right at any point in time. The robot 
 *    is trying to reach the bottom-right corner of the grid (marked 'Finish' in the 
 *    diagram below).
 *    How many possible unique paths are there?
 *
 *        Created:  11/21/2014 21:49:14
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1)
            return 1;
        if(m <= 0 || n <= 0)
            return 0;
        
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }

    int uniquePaths_DP(int m, int n){
        vector<int> row(n + 1, 0);
        vector<vector<int> > dp(m + 1, row);
        
        for(int i = 1; i <= n; i ++)
            dp[1][i] = 1;
            
        for(int j = 1; j <= m; j ++)
            dp[j][1] = 1;
        
        for(int i = 2; i <= m; i ++)
            for(int j = 2; j <= n; j ++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                
        return dp[m][n];
    }
};

int main(){
    Solution sol;

    assert(sol.uniquePaths(1, 1) == 1 && "failed in test 1");
    assert(sol.uniquePaths(2, 2) == 2 && "failed in test 2");
    assert(sol.uniquePaths(8, 9) == sol.uniquePaths_DP(8, 9) && "failed in test 3");
    cout << "Passed all tests!" << endl;

    return 0;
}
