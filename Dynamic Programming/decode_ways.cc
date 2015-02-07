/*
 * =====================================================================================
 *
 *       Filename:  decode_ways.c
 *
 *    Description:  A message containing letters from A-Z is being encoded to numbers using the following mapping:

                    'A' -> 1
                    'B' -> 2
                    ...
                    'Z' -> 26
                    Given an encoded message containing digits, determine the total number of ways to decode it.

                    For example,
                    Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

                    The number of ways decoding "12" is 2.
 *
 *        Created:  02/06/2015 21:24:51
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:

    // dp
    int numDecodings(string s) {
        if(s.empty())   return 0;
        
        int n = s.size();
        vector<int> dp(n, 0);
        
        if(s[0] == '0') return 0;
        
        dp[0] = 1;
        if(n == 1)  return dp[0];
        
        // corner cases: the main transformation equation is : dp[i] = dp[i-1] + dp[i-2]
        if(s[1] != '0'){
            if(s[0] == '1' || (s[0] == '2' && s[1] <= '6'))
                dp[1] = 2;
            else 
                dp[1] = 1;
        }
        else{
            if(s[0] > '2') dp[1] = 0;
            else dp[1] = 1;
        }
        
        
        // main body
        for(int i = 2; i < n; i++){
            if(s[i] == '0'){
                if(s[i-1] <= '2')    dp[i] = dp[i-2];
                else    return 0;
            }
            else if(s[i-1] == '1' || (s[i-1] == 2 && s[i] <= '6')){
                dp[i] = dp[i-2] + dp[i-1];
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        
        return dp[n-1];
    }
};

