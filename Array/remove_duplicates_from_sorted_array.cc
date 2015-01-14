/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_sorted_array.cc
 *
 *    Description:  remove duplicates from sorted array
 *
 *        Created:  01/13/2015 23:35:38
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 1)  return n;
        
        int i = 1;
        int j = 0;
        
        while(i < n){
            if(A[i] == A[j]){
                i++;
            }
            else{
                j++;
                A[j] = A[i];
                i++;
            }
        }
        
        return j+1;
    }
};
