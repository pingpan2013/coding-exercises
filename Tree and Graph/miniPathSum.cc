/*
 * =====================================================================================
 *           Desc:  Given a m x n grid filled with non-negative numbers, find a path 
 *                  from top left to bottom right which minimizes the sum of all numbers 
 *                  along its path.
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    // DP
    int minPathSum(vector<vector<int> > grid){
        int row = grid.size();
        int col = grid[0].size();
        
        int dp[row][col];
        // initiate DP
        for(int i = 1; i < row; i ++)
            dp[i][0] = dp[i-1][0] + grid[i][0];

        for(int j = 1; j < col; j ++)
            dp[0][j] = dp[0][j-1] + grid[0][j];

        // DP
        for(int m = 1; i < row; i ++)
            for(int n = 1; n < col; n++)
                dp[m][n] = min(dp[m-1][n], dp[m][n-1] + grid[m][n]);

        return dp[row-1][col-1];
    }
};



