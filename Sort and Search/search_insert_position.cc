/*
 * =====================================================================================
 *
 *    Description:  search insert position
 *        Created:  09/26/2014 04:05:00 PM
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n == 0)  return 0;
        
        int l = 0;
        int r = n-1;
        while(l <= r){
            int m = (r-l)/2 + l;
            
            if(A[m] == target)  return m;
            else if(A[m] > target){
                if((m-1 >= l && A[m-1] < target) || m-1 < l) return m;
                r = m-1;
            }
            else{
                if((m+1 <= r && target < A[m+1]) || m+1 > r) return m+1; 
                l = m+1;
            }
        }
    }
};

int main(){
    Solution sol;
    int A[] = {1, 3, 5};
    cout << sol.searchInsert(A, 3, 0) << endl;

    return 0;
}
