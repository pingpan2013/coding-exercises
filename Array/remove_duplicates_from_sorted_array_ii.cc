/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_sorted_array_ii.cc
 *
 *    Description:  remove duplicates from sorted array II
 *
 *        Created:  01/13/2015 23:36:24
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2)  return n;
        
        int i = 1;
        int j = 0;
        
        int cnt = 0;
        while(i < n){
            if(A[i] == A[j]){
                cnt ++;
                
                if(cnt < 2){
                    A[++j] = A[i];
                }
                i++;
            }
            else{
                cnt = 0;
                A[++j] = A[i];
                i++;
            }
        }
        
        return j+1;
    }
};

