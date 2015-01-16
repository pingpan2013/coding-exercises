/*
 * =====================================================================================
 *
 *       Filename:  decode_ways.cc
 *
 *    Description:  decode ways
 *
 *        Created:  01/16/2015 17:05:02
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // we assume that s only contains with digits
    int numDecodings(string s) {
        if(s.empty())   return 0;
        
        int n = s.length();
        vector<int> dp(n, 0);
        
        if(s[0] != '0')   dp[0] = 1;
        if(n == 1)  return dp[0];
        
        if(s[0] != '0' && s[1] != '0')  dp[1]++;
        if(isvalid(s.substr(0, 2)))     dp[1]++;
        
        for(int i = 2; i < n; i ++){
            if(s[i] != '0') dp[i] += dp[i-1];
            
            if(isvalid(s.substr(i-1, 2)))
                dp[i] += dp[i-2];
        }
                
        return dp[n-1];
    }
    
private:
    bool isvalid(const string &s){
        // or use atoi
        assert(s.size() == 2);
        if(s[0] == '0') return false;
        if(s[0] > '2' || (s[0] == '2' && s[1] > '6'))   return false;
        return true;
    }
};
