/*
 * =====================================================================================
 *
 *       Filename:  search_in_rotated_sorted_arr_ii.cc
 *
 *    Description:  search in rotated sorted arr, duplicates in the array are allowed
 *
 *        Created:  02/16/2015 15:32:17
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n == 0)  return false;
        
        int l = 0;
        int r = n - 1;
        while(l <= r){
            int m = (r - l)/2 + l;
            
            if(A[m] == target)  return true;
            if(A[m] < A[l]){
                if(target > A[m] && target <= A[r]){
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            else if(A[m] > A[l]){
                if(target < A[m] && target >= A[l]){
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            else{
                l = l + 1;    // core point
            }
        }
        
        return false;
    }
};

