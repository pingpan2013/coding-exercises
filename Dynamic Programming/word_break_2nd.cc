/*
 * =====================================================================================
 *
 *       Filename:  word_break_2nd.cc
 *
 *    Description:  word break, 2nd try
 *
 *        Created:  02/21/2015 13:57:17
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // 1. dfs
    // 2. dp
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty())   return true;
        
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && dict.find(s.substr(j, (i-1) - j + 1)) != dict.end()){
                    dp[i] = true;
                    break;
                }    
            }
        }
            
        return dp[n];
    }
};
