/*
 * =====================================================================================
 *
 *       Filename:  palindrome_partitioning_II_2nd.cc
 *
 *    Description:  2nd try
 *
 *        Created:  02/06/2015 17:20:50
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    // DP
    // 1.First compute the look-up table instead of checking dynamically every time
    // This is the key part to reduce time complexity, otherwise TLE
    // 
    // 2.Then utilize DP
    int minCut(string s) {
        if(s.empty())
            return 0;
        
        // 1.construct the table using dp !! Otherwise TLE
        int n = s.size();
        vector<vector<bool> > table(n, vector<bool>(n, false));
        
        // DP: if s[i]==s[j] && s[i+1:j-1] is palindrome => s[i:j] is palindrome
        for(int i = n-1; i >= 0; i --)
            for(int j = i; j < n; j ++){
                if(s[i] == s[j] && (j-i < 2 || table[i+1][j-1])){
                    table[i][j] = true;
                }
            }
            
            
        // 2.dp to find the minimal cuts
        vector<int> dp(n, INT_MAX);  // Pay attention to the initialization part
        dp[0] = 0;
        for(int i = 1; i < n; i++){
            if(table[0][i]) dp[i] = 0;
            else{
                for(int j = 0; j < i; j++){
                    if(table[j+1][i]){
                        dp[i] = min(dp[i], dp[j]+1);
                    }
                }
            }
        }
        
        return dp[n-1];
    }
};


