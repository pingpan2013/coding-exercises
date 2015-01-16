/*
 * =====================================================================================
 *
 *       Filename:  search_in_rotated_array_ii.cc
 *
 *    Description:  search in rotated array II
 *
 *        Created:  01/15/2015 20:20:06
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    bool search(int A[], int n, int target) {
        if(n <= 0)  return false;
        
        int l = 0;
        int h = n-1;
        
        while(l <= h){
            int mid = (h - l)/2 + l;
            
            if(A[mid] == target)    return true;
            
            if(A[mid] > A[l]){
                if(target >= A[l] && target < A[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else if(A[mid] < A[l]){
                if(target > A[mid] && target <= A[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
            else{
                // if ==, just move one step further
                l++;
            }
        }
        
        return false;
    }
};
