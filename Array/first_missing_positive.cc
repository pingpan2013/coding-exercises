/*
 * =====================================================================================
 *
 *       Filename:  first_missing_positive.cc
 *
 *    Description:  find the first missing positive integer
 *
 *        Created:  02/02/2015 11:11:12
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */


class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // method 1: if infinitely extra space is used, just use a flag array
       
        // A few observations: 1. A[i] should be the (A[i]-1)th element ( 0 based index)
        //                     2. After swapping, if A[i] != i+1, return i+1     
        
        // method 2: swap swap swap!!
        if(n == 0)  return 1;
        
        for(int i = 0; i < n; i ++){
            while(A[i] != i+1 && A[i] < n && A[i] > 0 && A[i] != A[A[i]-1]){  // attention A[i] != A[A[i]-1] here, in case of
                swap(A[i], A[A[i]-1]);                                        // infinitely loop, e.g.  [1, 1]
            }                                                       // The A[A[i]-1] already occured, then no need to swap
        }
        
        for(int i = 0; i < n; i ++){
            if(A[i] != i+1) return i+1;
        }
        
        return n+1;
    }
};


