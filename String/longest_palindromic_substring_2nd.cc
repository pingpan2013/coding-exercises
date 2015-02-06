/*
 * =====================================================================================
 *
 *       Filename:  longest_palindromic_substring_2nd.cc
 *
 *    Description:  2nd try
 *
 *        Created:  02/06/2015 18:43:13
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // 1. DP -----> TLE
    // O(n^2) space and O(n^2) time
    string longestPalindrome_(string s) {
        if(s.empty())   return "";
        
        int n = s.size();
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        
        int st = -1;
        int len = -1;
        
        for(int i = n-1; i >= 0; i--)
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j-i < 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    
                    if(j-i+1 > len){
                        st = i;
                        len = j-i+1;
                    }
                }
            }
        
        return s.substr(st, len);
    }
    
    // 2. expand from the center
    //    time complexity O(n^2), spcae O(1)
    string longestPalindrome(string s){
        if(s.empty())   return "";
        
        string l_substr = s.substr(0, 1);
        int n = s.size();
        
        for(int i = 0; i < n-1; i++){
            string s1 = expand(s, i, i);
            if(s1.size() > l_substr.size()){
                l_substr = s1;
            }
            
            string s2 = expand(s, i, i+1);
            if(s2.size() > l_substr.size()){
                l_substr = s2;
            }
        }
        
        return l_substr;
    }
    
private:
    string expand(string &s, int i, int j){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        
        return s.substr(i+1, j-i-1);
    }
};



