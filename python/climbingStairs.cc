/*
 * =====================================================================================
 *    Description:  You are climbing a stair case. It takes n steps to reach to 
 *                  the top.
 *        Created:  09/20/2014 05:36:08 PM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */


#include "tree.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    // use recursion
    unsigned climbingStairs(int n){
        if(n == 1)  return 1;
        if(n == 2)  return 2;

        return climbingStairs(n - 1) + climbingStairs(n -2);
    }
    
    // use DP
    unsigned climbingStairs_dp(int n){
        vector<int> result(n+1, 0); 
        result[1] = 1;
        result[2] = 2;

        for(int i = 3; i <= n; i ++){
            result[i] = result[i - 1] + result[i - 2];
        }
        return result[n];
    }
};

int main(){
    Solution sol;
    cout << sol.climbingStairs(3) << endl;
    cout << sol.climbingStairs_dp(3) << endl;
    cout << sol.climbingStairs(4) << endl;
    cout << sol.climbingStairs_dp(4) << endl;
    cout << sol.climbingStairs(10) << endl;
    cout << sol.climbingStairs_dp(10) << endl;

    return 0;
}




