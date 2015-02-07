/*
 * =====================================================================================
 *
 *       Filename:  backpack_ii.cc
 *
 *    Description:  classic backpack problem
 *
 *        Created:  02/05/2015 16:25:06
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
     
    // Recursion
    // DESC: the final result can be divided into two parts, it either contains
    //       the nth item or not
    // RESU: TLE
    int backPackII_(int m, vector<int> A, vector<int> V) {
        // write your code here
        if(m == 0 || A.size() == 0) return 0;
        
        int n = A.size();
        vector<int> part(A.begin(), A.end()-1);
        
        // if the nth item oversizes the total size
        if(A[n-1] > m){
            return backPackII_(m, part, V);
        }
        
        // two parts: nth item is not included and is included
        return max(backPackII_(m, part, V), V[n-1] + backPackII_(m-A[n-1], part, V));
    }
   



    // DP, classical DP problem
    int backPackII(int W, vector<int> wt, vector<int> val){
        int n = wt.size();
        
        if(W == 0 || n == 0)    return 0;
        
        vector<vector<int> > dp(n+1, vector<int>(W+1, 0));
        
        for(int i = 1; i <= n; i++)
            for(int w = 1; w <= W; w++){
                if(wt[i-1] > w)   // if ith item's size is bigger than the capacity
                    dp[i][w] = dp[i-1][w];
                else
                    dp[i][w] = max(val[i-1] + dp[i-1][w-val[i-1]], dp[i-1][w]);
            }
        

        for(auto itr : dp){
            for(auto it : itr){
                cout << it << " ";
            }
            cout << endl;
        }

        return dp[n][W];
    }
};


int main(){
    vector<int> wt({1, 2, 3});
    vector<int> val({2, 3, 4});

    Solution sln;
    cout << sln.backPackII(5 , wt, val) << endl;

    return 0;
}
