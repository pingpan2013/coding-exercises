/*
 * =====================================================================================
 *       Filename:  num_of_distinct_subsequence.cc
 *
 *    Description: Given a string S and a string T, count the number of distinct 
 * 		subsequences of T in S.
 *
 *		A subsequence of a string is a new string which is formed from the 
 *		original string by deleting some (can be none) of the characters 
 *		without disturbing the relative positions of the remaining characters. 
 *		(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 *
 *		Here is an example:
 *		S = "rabbbit", T = "rabbit", return 3. 
 *
 *        Created:  11/08/2014 17:09:03
 * =====================================================================================
 */


/* 
 * When you see string problem that is about subsequence or matcing, DP should come
 * to your mind naturally! 
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int numDistinct(string S, string T){
        vector<int> row(T.length(), 0);
        vector<vector<int> > dp(S.length(), row);

        // initialization, if T is empty, dp should return 1
        for(int i = 0; i < S.;length(); i ++)
            dp[i][0] = 1;
        
        // dynamic part
        for(int i = 0; i < S.length(); i ++)
            for(int j = 0; j < T.length(); j ++){
                if(S[i] == T[j]) 
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
    }

};

int main(){
    Solution sol;


    return 0;
}
