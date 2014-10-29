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

class Solution{
    public:
        unsigned searchInsert(int A[], int n, int target){
            int l = 0;
            int r = n-1;
            
            if(A[0] >= target)
                return 0;
            if(A[n-1] <= target)
                return n-1;

            while(l <= r){
                int mid = (l+r)/2;
                if(A[mid] > target && A[mid-1] < target )
                    return mid;
                if(A[mid] == target)
                    return mid;
                else if(A[mid] > target)
                    r = mid - 1;
                else if(A[mid] < target)
                    l = mid + 1;
            }
        }
};


int main(){
    Solution sol;
    int A[] = {1, 3, 5, 6};
    cout << sol.searchInsert(A, 4, 5) << endl;
    cout << sol.searchInsert(A, 4, 2) << endl;
    cout << sol.searchInsert(A, 4, 0) << endl;
    cout << sol.searchInsert(A, 4, 7) << endl;

}
