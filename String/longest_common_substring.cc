/*
 * =====================================================================================
 *
 *       Filename:  longest_common_substring.cc
 *
 *    Description:  longest common substring
 *
 *        Created:  01/16/2015 15:03:33
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int longestCommonSubstring(string &s1, string &s2){
        if(s1.empty() || s2.empty())    return 0;

        int m = s1.length();
        int n = s2.length();

        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

        int maxLen = 0;
        int st = 0;
        for(int i = 1; i <= m; i ++)
            for(int j = 1; j <= n; j++){
                dp[i][j] = (s1[i-1] == s2[j-1]) ? dp[i-1][j-1] + 1 : 0;
                
                if(dp[i][j] > maxLen){
                    maxLen = dp[i][j];
                    st = i;
                }
            }

        string substring;
        
        if(maxLen != 0) 
            substring = s1.substr(st-maxLen, maxLen);
        cout << "Longest common substring: "<< substring << endl;

        return maxLen;
    }
};

int main(){
    Solution sln;

    string s1 = "a";
    string s2 = "b";
    cout << sln.longestCommonSubstring(s1, s2) << endl;
        
    s1.push_back('b');
    s2.push_back('a');
    cout << sln.longestCommonSubstring(s1, s2) << endl;

    s1 = "abcdef";
    s2 = "bcdefg";
    cout << sln.longestCommonSubstring(s1, s2) << endl;

    return 0;
}
