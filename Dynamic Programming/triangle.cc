/*
 * =====================================================================================
 *
 *       Filename:  triangle.cc
 *
 *    Description:  Triangle
 *
 *        Created:  01/09/2015 18:56:18
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Method 1: Space complexity O(m*n)
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty() || triangle[0].empty())
            return 0;
        
        int m = triangle.size();
        int n = triangle[m-1].size();
        
        vector<int> row(n, 0);
        vector<vector<int> > dp(m, row);
        dp[0][0] = triangle[0][0];
            
        for(int i = 1; i < m; i++)
            for(int j = 0; j <= i;  j++){
                if(j == 0){ 
                    dp[i][0] = dp[i-1][0] + triangle[i][0];
                }
                else if(j == i){ 
                    dp[i][i] = dp[i-1][i-1] + triangle[i][i];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                }
            }
       
        display(dp);

        sort(dp[m-1].begin(), dp[m-1].end());
        return dp[m-1][0];
    }
    
    void display(vector<vector<int> > &vec){
        for(auto itr1 : vec){
            for(auto itr2 : itr1){
                cout << itr2 << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Method 2:
};


int main(){
    vector<vector<int> > vec;
    vec.push_back(vector<int>({ 1 }));
    vec.push_back(vector<int>({ 2, 3 }));
    Solution sol;
    
    cout << sol.minimumTotal(vec) << endl;
    
    return 0;
}
