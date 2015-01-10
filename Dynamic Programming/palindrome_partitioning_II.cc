/*
 * =====================================================================================
 *
 *       Filename:  palindrome_partitioning_II.cc
 *
 *    Description:  Given a string s, partition s such that every substring of the 
 *                  partition is a palindrome.
 *
 *                  Return the minimum cuts needed for a palindrome partitioning of s.
 *
 *                  For example, given s = "aab",
 *                  Return 1 since the palindrome partitioning ["aa","b"] could be 
 *                  produced using 1 cut.
 *
 *        Created:  01/10/2015 11:36:47
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
    // Passed small testcases
    // TLE for large test cases in leetCode OJ
    int minCut(string s) {
        if(s.empty())   return 0;
        if(s.size() == 1)   return 0;
        
        int n = s.size();
        vector<int> dp(n, 0);
        
        for(int i = 1; i < n; i++){
            int minCut = INT_MAX;
            
            string temp1 = s.substr(0, i+1);
            if(isvalid(temp1)) minCut = 0;
            else{
                // TODO:
                // This part leads to TLE, build a look-up table in preprocessing to reduce the time cost
                for(int j = 0; j < i; j++){
                    string temp1 = s.substr(j+1, i-j); 
                    if(isvalid(temp1)) 
                        minCut = min(minCut, dp[j] + 1);
                }
            }
            dp[i] = minCut;
        }
        
        return dp[n-1];
    }

private:   
    bool isvalid(string &s){
        int i = 0;
        int j = s.size()-1;
        
        while(i < j){
            if(s[i] != s[j])    return false;
            
            i++;
            j--;
        }
        
        return true;
    }
};

int main(){
    Solution sol;
    string s("abccba");
    assert(sol.minCut(s) == 0 && "Failed in test 1");
    
    s.pop_back();
    assert(sol.minCut(s) == 1 && "Failed in test 2");
    
    s = "";
    assert(sol.minCut(s) == 0 && "Failed in test 3");

    s.push_back('a'); 
    assert(sol.minCut(s) == 0 && "Failed in test 4");
    
    s = "abcdefggfedcbamn";
    assert(sol.minCut(s) == 2 && "Failed in test 5");

    cout << "Passed all test cases!" << endl;

    return 0;
}
