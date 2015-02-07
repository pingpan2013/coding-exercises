/*
 * =====================================================================================
 *
 *       Filename:  dungeon_game.cc
 *
 *    Description:  dungeon game
 *
 *        Created:  02/07/2015 15:21:46
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // thought:
    // 1. dfs is hard here since it cannot choose one optimal path
    // 2. dp, bottom-up
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
        if(m == 0)  return 0;
        
        int n = dungeon[0].size();
        if(n == 0)  return 0;
        
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for(int i = m-1; i >= 0; i--)
            for(int j = n-1; j >= 0; j--){
                int cur = dungeon[i][j];
                int neighbor = 0;
                
                if(i+1 < m && j+1 < n){
                    neighbor = min(dp[i+1][j], dp[i][j+1]);
                }
                else if(j == n-1 && i == m-1){
                    neighbor = 1;
                }
                else if(i == m-1){
                    neighbor = dp[i][j+1];
                }
                else if(j == n-1){
                    neighbor = dp[i+1][j];
                }
                
                cur = cur - neighbor;
                dp[i][j] = (cur >= 0) ? 1 : -cur;
            }
        
        return dp[0][0];
    }
};



