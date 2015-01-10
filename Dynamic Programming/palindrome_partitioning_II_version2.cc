class Solution {
public:
    int minCut(string s) {
        if(s.empty())   return 0;
        if(s.size() == 1)   return 0;
        
        int n = s.size();
        vector<int> dp(n, 0);
        
        // Preprocessing:
        // Preprocessing to build up the look-up table
        // table[i][j] = true if s[i:j] is palindrome
        //             = false if not
        // 
        // This is the key part to reduce the time complexity:
        // Using dp:
        // if(s[i] == s[j])  table[i][j] = table[i+1][j-1] 
        // note that in order to get table[i][j] we first need to get table[i+1][]
        //                          so we need to build the table for top
        vector<vector<bool> > table(n, vector<bool>(n, false));
        for(int i = n-1; i >= 0; i--)
            for(int j = i; j < n; j++){
                if(s[i] == s[j]){
                    if(j-i < 2 || table[i+1][j-1])
                        table[i][j] = true;
                }
            }
        
        // mian body
        for(int i = 1; i < n; i++){
            int minCut = INT_MAX;
            if(table[0][i]) minCut = 0;
            else{
                for(int j = 0; j < i; j++){
                    if(table[j+1][i]) 
                        minCut = min(minCut, dp[j] + 1);
                }
            }
            dp[i] = minCut;
        }
        
        return dp[n-1];
    }
};

