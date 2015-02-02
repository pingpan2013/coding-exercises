/*
 * =====================================================================================
 *
 *       Filename:  maximum_product_subarray.cc
 *
 *    Description:  maximum product subarray
 *
 *        Created:  02/02/2015 15:05:29
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n == 0)  return 0;
        
        int local_max = A[0];
        int local_min = A[0];
        int global_max = A[0];
        
        for(int i = 1; i < n; i ++){
            int temp = local_max;  // backup
            
            local_max = max(max(A[i], local_max*A[i]), local_min*A[i]);
            local_min = min(min(A[i], local_min*A[i]), temp * A[i]);
            global_max = max(local_max, global_max);
        }
        
        return global_max;
    }
};


