/*
 * =====================================================================================
 *
 *       Filename:  maximum_product_subarray.cc
 *
 *    Description:  maximum product subarray
 *
 *        Created:  02/22/2015 01:45:25
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n == 1)  return A[0];
        
        int localMin = A[0];
        int localMax = A[0];
        int gMax = A[0];
        
        for(int i = 1; i < n; i ++){
            int tmp = localMax;
            localMax = max(max(localMin*A[i], localMax*A[i]), A[i]);
            localMin = min(min(localMin*A[i], tmp*A[i]), A[i]);
            
            gMax = max(gMax, localMax);
        }
        
        return gMax;
    }
};

