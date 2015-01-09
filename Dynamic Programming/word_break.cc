/*
 * =====================================================================================
 *
 *       Filename:  word_break.cc
 *
 *    Description:  Given a string s and a dictionary of words dict, determine if s 
                    can be segmented into a space-separated sequence of one or more 
                    dictionary words.

                    For example, given
                    s = "leetcode",
                    dict = ["leet", "code"].

                    Return true because "leetcode" can be segmented as "leet code".
 *
 *        Created:  01/08/2015 21:32:57
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // one-demension DP
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.length()+1, false);     
        dp[0] = true;
        
        for(int i = 1; i <= s.length(); i ++){
            for(int j = 0; j < i; j++){
                // update dp[i+1]
                if(dp[j] && dict.find(s.substr(j, i-j)) != dict.end()){  // dont confuse the index of the original array and 
                    dp[i] = true;                                        // the index of dp
                    break;
                }
            }
        }
        
        return dp[s.length()];
    }
};
