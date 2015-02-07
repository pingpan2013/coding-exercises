/*
 * =====================================================================================
 *
 *       Filename:  backpack.cc
 *
 *    Description:  0-1 backpack
 *                  Given n items with size A[i], an integer m denotes the size of a backpack. How full you can fill this backpack? 
 *
 *        Created:  02/05/2015 14:51:33
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        if(A.empty())   return 0;
        
        vector<bool> dp(m+1, false);
        dp[0] = true;
        
        int index = 0;
        for(int i = 0; i < A.size(); i++)
            for(int j = m; j >= A[i]; j--){
                dp[j] = dp[j] || dp[j-A[i]];
                
                if(dp[j]){
                    index = max(j, index);
                }
            }
            
        return index;
    }
};

