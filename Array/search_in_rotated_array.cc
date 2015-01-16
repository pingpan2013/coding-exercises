/*
 * =====================================================================================
 *
 *       Filename:  search_in_rotated_array.cc
 *
 *    Description:  search in rotated array
 *
 *        Created:  01/15/2015 20:19:35
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
      int search(int A[], int n, int target){
        return helper(A, 0, n-1, target);
    }

private:
    // can use iteration or recursion
    // since only rotate once, either the left or the right part of the array should be sorted after rotation
    int helper(int A[], int l, int h, int target){
        assert(l >= 0 && h >= 0 && l <= h && "wrong parameters!");
        int mid;
        
        while(l <= h){
            mid = (l + h)/2;
            if(A[mid] == target)
                return mid;
            // if left part is sorted 
            if(A[l] <= A[mid]){
                if(target >= A[l] && target < A[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else{
                if(target > A[mid] && target <= A[h])
                    l = mid + 1;
                else
                    h = mid - 1;
            }
        }

        return -1;
    }
};
