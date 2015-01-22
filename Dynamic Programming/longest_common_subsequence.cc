/*
 * =====================================================================================
 *
 *       Filename:  longest_common_subsequence.cc
 *
 *    Description:  longest common subsequence
 *
 *        Created:  01/21/2015 22:54:39
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution{
public:
    // 2 dimension dp
    int longestCommonSubstring(string &s1, string &s2){
        if(s1.empty() || s2.empty())    return 0;

        int m = s1.size();
        int n = s2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= m; i ++)
            for(int j = 1; j <= n; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        return dp[m][n];
    }

    // 1 dimension dp
    int longestCommonSubstring_(string &s1, string &s2){
        if(s1.empty() || s2.empty())    return 0;
        
        int n = s1.size();
        int m = s2.size();
        vector<int> dp(m+1, 0);

        for(int i = 1; i <= n; i++){
            int prev = dp[0];   // backup diagonal element
            for(int j = 1; j <= m; j++){
                int temp = dp[j];   // backup the data from previous iteration

                if(s1[i-1] == s2[j-1])
                    dp[j] = prev + 1;
                else
                    dp[j] = max(dp[j], dp[j-1]);
                
                prev = temp;
            }
        }

        return dp[m];

    }
};


int main(){
    Solution sol;
    string s1 = "ABDFEGMN";
    string s2 = "ACDEM";

    assert(sol.longestCommonSubstring(s1, s2) == 4 && "failed test 1");
    assert(sol.longestCommonSubstring_(s1, s2) == 4 && "failed test 2");

    return 0;
}


