/*
 * =====================================================================================
 *
 *       Filename:  longest_palindromic_substring.cc
 *
 *    Description:  longest palindromic substring
 *
 *        Created:  01/16/2015 09:46:57
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    // Method 1: btrute-force solution
    // O(n^3)
    
    // Method 2: two demesionial DP
    // Space O(n^2) time O(n^2)
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0)  return s;
        
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        
        int maxlen = 0;
        int st = 0;
        int nd = 0;
        
        for(int i = n-1; i >= 0; i --)
            for(int j = i; j < n; j++){
                dp[i][j] = (s[i] == s[j]) && (j <= i+1 || dp[i+1][j-1]);
                
                // update maxlen
                if(dp[i][j] && (j-i+1 > maxlen)){
                    maxlen = j-i+1;
                    st = i;
                    nd = j;
                }
            }
        
        return s.substr(st, maxlen);
    }
};

int main(){
    Solution sln;
    string s("abcba");
    string s_res("abcba");
    
    assert(sln.longestPalindrome(s) == s_res && "Failed in test 1"); 

    s.push_back('a');
    assert(sln.longestPalindrome(s) == s_res && "Failed in test 2"); 

    s = "abccbdef";
    s_res = "bccb";
    assert(sln.longestPalindrome(s) == s_res && "Failed in test 3"); 
    
    cout << "Passed all test cases!" << endl;

    return 0;
}






