/*
 * =====================================================================================
 *
 *       Filename:  search_in_a_range.cc
 *
 *    Description:  search in a range
 *
 *        Created:  02/14/2015 16:30:25
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // first get the lowest index
        vector<int> result({-1, -1});
        if(n == 0)  return result;
        
        int l = 0;
        int r = n-1;
        while(l <= r){
            int m = (r-l)/2 + l;
            
            if(A[m] >= target){ // even if the target already found, go to the left part
                r = m - 1;
            } 
            else{
                l = m + 1;
            }
        }
        
        if(l < n && A[l] == target){
            result[0] = l;
        }
        else    return result;
        
        // then get the highest index
        r = n-1;
        while(l <= r){
            int m = (r-l)/2 + l;
            if(A[m] <= target){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        
        result[1] = r;
        return result;
    }
};

