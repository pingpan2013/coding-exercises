/*
 * =====================================================================================
 *
 *       Filename:  distinct_subsequences.cc
 *
 *    Description:  Given a string S and a string T, count the number of distinct 
                    subsequences of T in S.

                    A subsequence of a string is a new string which is formed 
                    from the original string by deleting some (can be none) 
                    of the characters without disturbing the relative positions 
                    of the remaining characters. (ie, "ACE" is a subsequence of 
                    "ABCDE" while "AEC" is not).

                    Here is an example:
                    S = "rabbbit", T = "rabbit"
                    Return 3.  
 *
 *        Created:  02/17/2015 23:23:21
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>

using namespace std;

int numDistinct(string S, string T) {
    if(T.empty())   return 1;
    if(S.empty())   return 0;
    
    int m = S.size();
    int n = T.size();

    vector<int> dp(m+1, 0);
    for(int i = 0; i <= m; i++){
        dp[i] = 1;
    }
    
    for(int i = 1; i <= n; i++){
        int pre = dp[0];
        dp[0] = 0;
        
        for(int j = 1; j <= m; j++){
            int lastDiag = dp[j];
            
            if(S[j-1] == T[i-1]){
                dp[j] = dp[j-1] + pre;
            }
            else{
                dp[j] = dp[j-1];
            }
            
            pre = lastDiag;
        }
    }
    
    return dp[m];
}

int main(){
    string S("b");
    string T("b");

    cout << numDistinct(S, T) << endl;

    return 0;
}

