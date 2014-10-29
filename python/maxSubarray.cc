/*
 * =====================================================================================
 *    Description:  Find the contiguous subarray within an array(containing
 *                  at least one number) which has the largest sum
 *
 *        Created:  09/27/2014 11:09:48 AM
 *       Compiler:  g++ 4.7.0
 * =====================================================================================
 */

#include <iostream>

using namespace std;

class Solution{
public:
    int maxSub(int A[], int l, int r){
        if(l == r)  return max(A[l], A[r]);
        
        int mid = (l + r) / 2;
        int lMax = maxSub(A, l, mid);
        int rMax = maxSub(A, mid+1, r);
        
        // Combine the left and right parts
        // It is obvious that the max subarray contains the item A[mid]
        int Max = A[mid];
        int sum = Max;
        for(int i = mid + 1; i <= r; i ++){
            sum += A[i];
            if(sum > Max)
                Max = sum;
        }
        
        sum = Max;
        for(int k = mid - 1; k >= l; k --){
            sum += A[k];
            if(sum > Max)
                Max = sum;
        }
        return max(max(lMax, rMax), Max);
    }

    // DC
    int maxSubarray(int A[], int n){
        int l = 0;
        int r = n - 1;

        int maxNum = maxSub(A, l, r);
        return maxNum;
    }
};

int main(){
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    cout << sol.maxSubarray(A, 9) << endl;
    return 0;
}
