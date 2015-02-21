/*
 * =====================================================================================
 *
 *       Filename:  palindrome_partitioning_II_3rd.c
 *
 *    Description:  3rd try
 *
 *        Created:  02/21/2015 00:58:31
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    int minCut(string s) {
        if(s.empty())   return 0;
        
        // construct the check table
        int n = s.size();
        vector<vector<bool>> table(n, vector<bool>(n, false));
        
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j <= n-1; j++){
                if(j == i || (j == i+1 && s[i] == s[j]) || (table[i+1][j-1] && s[i] == s[j])){
                    table[i][j] = true;
                }
            }
        }
        
        // dp
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        
        for(int i = 1; i < n; i++){
            if(table[0][i]) {
                dp[i] = 0;
                continue;
            }
            
            for(int j = 0; j < i; j++){
                if(table[j+1][i]){
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[n-1];
    }
};


