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
#include <cassert>

using namespace std;

class Solution{
public:
    int numDistinct(string S, string T){
        if(T.empty())   return 1;
        if(S.empty())   return 0;

        vector<int> row(T.length(), 0);
        vector<vector<int> > dp(S.length(), row);

        // initialization, if T is empty, dp should return 1
        for(int i = 0; i < S.length(); i ++)
            dp[i][0] = 1;
        
        displayVec(dp);

        // dynamic part
        for(int i = 1; i < S.length(); i ++){
            for(int j = 1; j < T.length(); j ++){
                if(S[i] == T[j]) 
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        displayVec(dp);
        
        int result = dp[S.length()-1][T.length()-1];
        return result; 
    }

private:
    void displayVec(vector<vector<int> > &vec){
        for(auto vec_row: vec){
            for(auto item: vec_row){
                cout << item << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Solution sol;
    
    string S("");
    string T("");
    assert(sol.numDistinct(S, T) == 1 && "failed in the given test!");

    T.append("rabbit");
    assert(sol.numDistinct(S, T) == 0 && "failed in the given test!");

    S.append("rabbbit");
    assert(sol.numDistinct(S, T) == 3 && "failed in the given test!");

    cout << "Passed all the tests!" << endl;
    return 0;
}
