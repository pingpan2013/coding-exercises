/*
 * =====================================================================================
 *
 *       Filename:  maximum_subarray.cc
 *
 *    Description:  maximum subarray
 *
 *        Created:  02/15/2015 00:54:38
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 0)  return 0;
        
        //int gMax = A[0];   // better use this way
        //int lMax = A[0];
        int gMax = INT_MIN;
        int lMax = INT_MIN;
        
        for(int i = 0; i < n; i++){
            lMax = max(lMax + A[i], A[i]); // lMax + A[i] may cause overflow in this case    
            gMax = max(gMax, lMax);
        }
        
        return gMax;
    }
};

int main(){
    int A[] = {-1};
    Solution sln;

    cout << sln.maxSubArray(A, 1) << endl;

    return 0;
}
