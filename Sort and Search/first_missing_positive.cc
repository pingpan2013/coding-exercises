/*
 * =====================================================================================
 *
 *       Filename:  first_missing_positive.cc
 *
 *    Description:  find the first missing positve integer
 *
 *        Created:  02/14/2015 20:30:53
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(n== 0)   return 1;
        
        for(int i = 0; i < n; i ++){
            while(A[i] > 0 && A[i] < n && A[i] != i+1 && A[A[i] - 1] != A[i]){
                swap(A[i], A[A[i] - 1]);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(A[i] != i+1)
                return i+1;
        }
        
        return n+1;
    }
};

