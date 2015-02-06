/*
 * =====================================================================================
 *
 *       Filename:  edit_distance.cc
 *
 *    Description:  Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
                    You have the following 3 operations permitted on a word:

                    a) Insert a character
                    b) Delete a character
                    c) Replace a character 
 *
 *        Created:  02/05/2015 21:27:01
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // dp
   int minDistance_(string word1, string word2) {
        if(word1.empty())   return word2.length();
        if(word2.empty())   return word1.length();
        
        int m = word1.length();
        int n = word2.length();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0)); 
        
        for(int i = 0; i <= n; i++) 
            dp[0][i] = i;
        
        for(int i = 0; i <= m; i++)
            dp[i][0] = i;
        
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
            
        return dp[m][n];
    }
    
    // one-demensional DP
    int minDistance(string word1, string word2){
        if(word1.empty())   return word2.length();
        if(word2.empty())   return word1.length();
        
        int m = word1.length();
        int n = word2.length();
        vector<int> dp(m+1, 0);
        
        // initialization
        for(int i = 0; i <= m; i++)
            dp[i] = i;
        
        // main body
        int pre;
        for(int i = 1; i <= n; i++){
            pre = dp[0];     // pre is dp[i-1][j-1]
            dp[0] = i;
            
            for(int j = 1; j <= m; j ++){
                int tmp = dp[j];
                
                if(word2[i-1] == word1[j-1]){
                    dp[j] = pre;
                }
                else{
                    dp[j] = min(min(dp[j-1], pre), dp[j]) + 1;
                }
                
                pre = tmp;
            }
        }
        
        return dp[m];
    }
};


