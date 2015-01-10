/*
 * =====================================================================================
 *
 *       Filename:  interleaving_string.cc
 *
 *    Description:  Given s1 and s2, find whether s3 is formed by the interleaving of
 *                  s1 and s2;
 *
 *        Created:  01/10/2015 00:04:56
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.empty() && s2.empty() && s3.empty())  return true;
        
        int m = s1.size();
        int n = s2.size();
        // initial test
        if(m + n != s3.size())  return false;
        
        vector<vector<bool> > dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        
        for(int i = 1; i <= m; i++){
            dp[i][0] = (s3[i-1] == s1[i-1] && dp[i-1][0]) ? true : false;
        }
        
        for(int i = 1; i <= n; i++){
            dp[0][i] = (s3[i-1] == s2[i-1] && dp[0][i-1]) ? true : false;
        }
        
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++){
                //if(s3[i+j-1] == s1[i-1] && s3[i+j-1] == s2[j-1]){
                //    dp[i][j] == (dp[i-1][j] || dp[i][j-1]);
                //}
                //else if(s3[i+j-1] == s1[i-1]){
                //    dp[i][j] = dp[i-1][j];
                //}
                //else if(s3[i+j-1] == s2[j-1]){
                //    dp[i][j] = dp[i][j-1];
                //}
                dp[i][j] = ((s3[i+j-1] == s1[i-1]) && dp[i-1][j]) || ((s3[i+j-1] == s2[j-1]) && dp[i][j-1]);
            }
            
        return dp[m][n];
    }
};



